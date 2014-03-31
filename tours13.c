#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef long long ll;
typedef struct item{
  int value;
  ll key;
  int pos;
} item;

typedef struct heap{
  int size;
  item **h;
  int d;
}heap;

static inline item* findmin(heap* h){
  if(h->size==0)return NULL;
  return h->h[1];
}

static inline item* makeitem(ll key,int value){
  item* res=malloc(sizeof(item));
  res->key=key;
  res->value=value;
  return res;
}
static inline int parent(heap* h,int x){
  if (x==1) return 0;
  return (int) ceil((float)(x-1)/h->d);
}
static inline void siftup(heap*h,item *i,int x){
  register int p=parent(h,x);
  while((p!=0)&&(h->h[p]->key > i->key)){
    h->h[x]=h->h[p];
    h->h[x]->pos=x;
    x=p;
    p=parent(h,x);
  }
  h->h[x]=i;
  h->h[x]->pos=x;
}

static inline item* insert(heap* h,ll key,int value){
  ++h->size;
  item *res=makeitem(key,value);
  siftup(h,res,h->size);
  return res;
}

#define min2(a,b) ((a)<(b)?(a):(b))
static inline int minchild(heap*h,int x){
  register int i,minc;
  minc=h->d*(x-1)+2;
  if(minc>h->size) return 0;
  i=minc+1;
  while(i<=min2(h->size,h->d*x+1)){
    if(h->h[i]->key < h->h[minc]->key){
      minc=i;
    }
    ++i;
  }
  return minc;
}

static inline void siftdown(heap*h,item*i,int x){
  register int c=minchild(h,x);
  while((c!=0) &&(h->h[c]->key < i->key)){
    h->h[x]=h->h[c];
    h->h[x]->pos=x;
    x=c;
    c=minchild(h,c);
  }
  h->h[x]=i;
  h->h[x]->pos=x;
}

static inline void delete(heap*h,item*i){
  item* j=h->h[h->size];
  if(i->pos !=j->pos){
    if(j->key<=i->key)siftup(h,j,i->pos);
    else siftdown(h,j,i->pos);
  }
  --h->size;
}

static inline void deletemin(heap*h){
  /*item *last=h->h[h->size];
  --h->size;
  if(h->size>0) siftdown(h,last,1);
  */
  delete(h,h->h[1]);
}

static inline heap* makeheap(int maxsize,int d){
  heap* res=malloc(sizeof(heap));
  res->h=malloc(sizeof(item*)*maxsize+10);
  res->size=0;
  res->d=d;
  return res;
}

static inline void freeheap(heap*h){
  free(h->h);
  free(h);
}

static inline void changekey(heap*h,item*i,ll k){
  ll ki=i->key;
  i->key=k;
  if(ki!=k){
    if(k<ki) siftup(h,i,i->pos);
    else siftdown(h,i,i->pos);
  }
}
#include <time.h>

void printitem(item* i){
  printf("#item: %d %lld \n",i->value,i->key);
}
/*
int main(){
  heap *h=makeheap(20,2);

  item *a=insert(h,10,1);
  item *c=insert(h,2,2);
  item *d=insert(h,4,3);
  item *e=insert(h,3,4);
  item *f=insert(h,1,5);
  item *g=insert(h,7,6);

  changekey(h,g,3);
  while(h->size){
    printitem(h->h[1]);
    deletemin(h);
  }
  freeheap(h);
  return 0;
}
*/
static inline long getLong(){
    long res=0;
    register char c;
    for(;;){
        c=getchar_unlocked();
        if(isdigit(c)) break;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res;
}
static inline int getInt(){
    int res=0;
    register char c;
    for(;;){
        c=getchar_unlocked();
        if(isdigit(c)) break;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res;
}
#define MAXS 1010
#define MAXC 99999999
typedef struct edge{
  long v[MAXS];
  int n[MAXS];
  int s;
}edge;
typedef struct graph{
  edge v[MAXS];
}graph;
int n,m;
graph g;
FILE *fi;
int a;
static inline void readgraph(){
  n=getInt();
  m=getInt();
  register int i,u,v;
  long w;
  for(i=1;i<=n;++i){
    g.v[i].s=0;
  }
  for(i=0;i<m;++i){
    //fscanf(fi,"%d%d%ld",&u,&v,&w);
    u=getInt();
    v=getInt();
    w=getLong();
    g.v[u].v[g.v[u].s]=w;
    g.v[u].n[g.v[u].s]=v;
    ++g.v[u].s;
  }
}
void dijkstra(int u){
  if(!g.v[u].s){
    printf("-1\n");
    return;
  }
  ll r[n+2];
  int i,j;
  heap *h=makeheap(n,a);
  item* hi[n+2];
  for(i=1;i<=n;++i){
    hi[i]=insert(h,MAXC,i);
  }
  changekey(h,hi[u],0);
  int run=0;
  while(h->size>0){
    item *curr=h->h[1];
    r[curr->value]=curr->key;
    deletemin(h);
    if(run<2){
      if(run==1){
        hi[u]=insert(h,MAXC,u); 
      }
      ++run;
    }
    if(run==2 && curr->value==u){
      printf("%lld\n",r[u]>=MAXC?-1:r[u]);
      freeheap(h);
      return;
    } 
    for(j=0;j<g.v[curr->value].s;++j){
      int visit=g.v[curr->value].n[j];
      item *dest=hi[visit];
      ll pathCost=curr->key+g.v[curr->value].v[j];
      if(pathCost<dest->key){
        changekey(h,dest,pathCost);
      }
    }
  }
}
void solve(){
  readgraph();
  register int i;
  a=m/n;if(a<4) a=4;
  //a=4;
  for(i=1;i<=n;++i) dijkstra(i);
}
int main(){
#ifdef Test
  fi=fopen("F1.INP","r");
#else
  fi=stdin;
#endif
  register int t;
  t=getInt();
  int i;
  for(i=0;i<t;++i) solve();
  return 0;
}
