#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef void* Object;
typedef struct FibHeap FibHeap;
typedef struct FibHeapElement FibHeapElement;
typedef unsigned char bool;

FibHeapElement *FibHeapGetRoot(FibHeap *heap);
unsigned int FibHeapGetSize(FibHeap *heap);
FibHeap *FibHeapMakeHeap();
FibHeapElement *FibHeapMinimum();
FibHeapElement *FibHeapInsert(FibHeap *heap, double key, Object value);
FibHeapElement *FibHeapExtractMin(FibHeap *heap);

void FibHeapConsolidate(FibHeap *heap);
void FibHeapLink(FibHeap *heap,FibHeapElement *y, FibHeapElement *x);
void FibHeapDecreaseKey(FibHeap* heap, FibHeapElement *element, double key);

Object FibHeapElementGetValue(FibHeapElement *); 
double FibHeapElementGetKey(FibHeapElement *);

#define TRUE 1
#define FALSE 0

int _comparisons = 0;

#ifdef INSTRUMENT
#define o (_comparisons++)
#else
/*
   This should probably be made something cleaner.  We don't want the compiler
   warnings, but we also don't want to waste time on an impotent assignment.  
   */
#define o (_comparisons = 1)
#endif

typedef struct pFibHeapElement pFibHeapElement;

struct FibHeap {
  pFibHeapElement *root;
  unsigned int size;
};

struct FibHeapElement {
  Object value;
  double key;
};


struct pFibHeapElement {
  FibHeapElement elem;
  pFibHeapElement *parent;
  pFibHeapElement *children;
  pFibHeapElement *next;
  pFibHeapElement *prev;
  bool mark;
  unsigned int degree;
};

static void Cut(FibHeap*, pFibHeapElement*, pFibHeapElement*);
static void CascadingCut(FibHeap*, pFibHeapElement*);

static void LL_Remove(pFibHeapElement *x) {
  if(o, x->prev == x) {
    /* only element in list */
  } else {
    x->prev->next = x->next;
    x->next->prev = x->prev;
  }  

  if(o,x->parent) {
    x->parent->degree--;
  }

  x->prev = x->next = 0;
}

static void LL_Insert(pFibHeapElement *x, pFibHeapElement *y) {
  y->prev = x;
  y->next = x->next;
  x->next->prev = y;
  x->next = y;
  y->parent = x->parent;

  if(o,x->parent)
    x->parent->degree++;
}

unsigned int FibHeapGetSize(FibHeap *heap) {
  return heap ? heap->size : 0;
}


Object FibHeapElementGetValue(FibHeapElement *el) {
  /* add erno */
  return el ? el->value : 0;
}
double FibHeapElementGetKey(FibHeapElement *el) {
  /* add erno */
  return el ? el->key : -1;
}



FibHeap *FibHeapMakeHeap() {
#ifdef INSTRUMENT
  _alloc;
#endif
  FibHeap *fh = (FibHeap*) malloc(sizeof(FibHeap));

  fh->size = 0;
  fh->root = 0;
  return fh;
}

FibHeapElement *FibHeapGetRoot(FibHeap *heap) {
  return (FibHeapElement*) heap->root;
}

FibHeapElement *FibHeapMinimum(FibHeap *heap) {
  return (FibHeapElement*) heap->root;
}

FibHeapElement *FibHeapInsert(FibHeap *heap, double key, Object value) {
#ifdef INSTRUMENT
  _alloc;
#endif
  pFibHeapElement *element = (pFibHeapElement*) malloc(sizeof(pFibHeapElement));
  element->parent = 0;
  element->children = 0;  
  element->next = element;  
  element->prev = element;  
  element->mark = TRUE;
  element->degree = 0;

  element->elem.value = value;
  element->elem.key = key;

  if(o,heap->root == 0) {
    heap->root = element;
  } else {
    LL_Insert(heap->root, element);
  }

  if(o,heap->root->elem.key > element->elem.key) 
    heap->root = element;

  heap->size++;  
  return (FibHeapElement*) element;
}

FibHeapElement* FibHeapExtractMin(FibHeap *heap) {
  pFibHeapElement *min = (pFibHeapElement*) FibHeapMinimum(heap);

  if(o,min != 0) {
    pFibHeapElement *child = min->children;
    pFibHeapElement *x;


    if(o,child) {
      do {
        pFibHeapElement *next = child->next;
        LL_Remove(child);
        LL_Insert(min, child);
        child = next;
      } while(o,child != min->children);
    }
    min->children = 0;

    x = min->next;
    LL_Remove(min);
    if(o,min == x)
      heap->root = 0;
    else {
      heap->root = x;
      FibHeapConsolidate(heap);
    }
    heap->size--;        
  }

  return (FibHeapElement *) min;
}


static long long nplog2(long long x){
	long long y;
  asm(
      "\tbsr %1,%0\n":"=r"(y):"r"(x)
     );
  return y;
}
#define ASIZE 15

void FibHeapConsolidate(FibHeap *heap) {
  /* Is 200 enough?  Is it too much?  Should it be a vector so I don't have to
   *  worry about it?
   */
#undef ASIZE
#ifndef ASIZE
  int ASIZE=(int)(nplog2(heap->size)+1);  
#endif
  //printf("AS=%d\n",ASIZE);
  pFibHeapElement *A[ASIZE];
  pFibHeapElement *w;
  unsigned int i;

  for(i=0; i<ASIZE; i++) 
    A[i] = 0;

  w = heap->root;

  while(o,(w=heap->root)) {
    pFibHeapElement *x = w;
    int d;

    if(o,w->prev == w)
      heap->root = 0;
    else 
      heap->root = w->next;

    LL_Remove(w);

    d = x->degree;
    while(o,A[d] != 0) {
      pFibHeapElement *y = A[d];
      if(o,x->elem.key > y->elem.key) {
        pFibHeapElement *tmp = x;
        x = y;
        y = tmp;
      }
      FibHeapLink(heap, (FibHeapElement *) y, (FibHeapElement *) x);
      A[d] = 0;
      d++;
    }  
    A[d] = x;
  }


  for(i=0; i<ASIZE; i++) {
    if(o,A[i] != 0) {
      if(o,heap->root == 0)  {
        heap->root = A[i];
        A[i]->next = A[i];
        A[i]->prev = A[i];
      } else 
        LL_Insert(heap->root,A[i]);
      if(o, heap->root->elem.key > A[i]->elem.key) {
        heap->root = A[i];
      }
    }
  }
}

void FibHeapLink(FibHeap *heap, FibHeapElement *_y, FibHeapElement *_x) {
  pFibHeapElement *x = (pFibHeapElement *) _x, *y = (pFibHeapElement *) _y;

  if(o,x->children) {
    LL_Insert(x->children, y);
  } else {
    x->children = y;
    y->parent = x;
    y->next = y;
    y->prev = y;
    x->degree = 1;
  }
  y->mark = FALSE;
  if(o,heap->root == y)
    heap->root = x;
}


void FibHeapDecreaseKey(FibHeap* heap, FibHeapElement *_element, double key) {
  pFibHeapElement *element = (pFibHeapElement *) _element, *parent;

  if(o,!element) {
    /* throw an error */
    return;
  }

  if(o,element->elem.key < key) {
    /* throw an error */
    return;
  }

  element->elem.key = key;

  parent = element->parent;


  if((o,parent) && (o,parent->elem.key > element->elem.key)) {
    Cut(heap, element, parent);
    CascadingCut(heap, parent);
  }  

  if(o,element->elem.key < heap->root->elem.key)  {
    heap->root = element;  
  }
}


static void Cut(FibHeap* heap, pFibHeapElement* x, pFibHeapElement* y) {
  if(o,y->children == x) {
    if(o,x->next != x) {
      y->children = x->next;
    } else y->children = 0;
  }
  LL_Remove(x);
  LL_Insert(heap->root, x);
  x->mark=FALSE;
}

static void CascadingCut(FibHeap* heap, pFibHeapElement* y) {
  pFibHeapElement *z = y->parent;

  if(o,z) {
    if(o,z->mark==FALSE)
      z->mark = TRUE;
    else {
      Cut(heap, y, z);
      CascadingCut(heap, z);
    }
  }
}


#define MAXS 1010
#define MAXC 678967896789
typedef struct edge{
  double v[MAXS];
  int n[MAXS];
  int s;
}edge;
typedef struct graph{
  edge v[MAXS];
  char i[MAXS];
  int s;
}graph;
double res[MAXS][MAXS];
long n,m;
graph g;
FILE *fi;
void readgraph(){
  fscanf(fi,"%ld%ld",&n,&m);
  long i,j;
  for(i=1;i<=n;++i){
    g.v[i].s=0;
  }
  memset(g.i,0,n+1);
  int u,v;
  long c;
  for(i=0;i<m;++i){
    fscanf(fi,"%d%d%ld",&u,&v,&c);
    if(!g.i[u]) g.i[u]=1;
    g.v[u].v[v]=c;
    g.v[u].n[g.v[u].s]=v;
    ++g.v[u].s;
  }
}
void dijkstra(int source){
  double *result=res[source];
  int i,j;
  if(!g.i[source]){
    for(i=1;i<=n;++i){
      result[i]=MAXC;
    }
    return;
  }
  int ml[n+1];
  FibHeapElement *entries[n+1];
  FibHeap *pq=FibHeapMakeHeap();
  char ind[n+1];
  memset(ind,0,n+1);
  for(i=1;i<=n;++i){
    ml[i]=i;
    entries[i]=FibHeapInsert(pq,MAXC,ml+i);
  }
  FibHeapDecreaseKey(pq,entries[source],0);
  while(FibHeapGetSize(pq)){
    /* get pass to n vertice  * log(n) extractMin */
    FibHeapElement *curr=FibHeapExtractMin(pq);
    int currV=*((int*) curr->value); /* value <=> vertice graph*/
    double currK = curr->key;
    //printf("%d %d %lf\n",source,currV,currK);
    //result.i[currV]=1;
    //result.v[currV]=currK;
    ind[currV]=1;
    result[currV]=currK;
    for(j=0;j<g.v[currV].s;++j){ /* all edge from vertice [currV] */
      i=g.v[currV].n[j];
      if(ind[i]) continue;
      double pathCost= currK+g.v[currV].v[i];
      FibHeapElement *dest= entries[i];
      if(pathCost< dest->key){
        FibHeapDecreaseKey(pq,dest,pathCost); /* ~~O(1)*/
      }	
    }
  }
}
void solve(){
  readgraph();
  int i,j;
  for(i=1;i<=n;++i){
    dijkstra(i);
  }
  for(i=1;i<=n;++i){
    double min=MAXC;
    for(j=1;j<=n;++j){
      if(i==j) continue;
      if(res[i][j]+res[j][i]<min) min=res[i][j]+res[j][i];
    }
    if(min>=MAXC) min=-1;
    printf("%.0lf\n",min);
  }
}
int main(){
#ifdef T
  fi=fopen("FBH.INP","r");
#else
  fi=stdin;
#endif
  int i,test;
  fscanf(fi,"%d",&test);
  for(i=0;i<test;++i){
    solve();
  }
  return 0;
}
