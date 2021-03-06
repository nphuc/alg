#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define f_i "A.INP"
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

item* findmin(heap* h){
  if(h->size==0)return NULL;
  return h->h[1];
}

item* makeitem(ll key,int value){
  item* res=malloc(sizeof(item));
  res->key=key;
  res->value=value;
  return res;
}
int parent(heap* h,int x){
  if (x==1) return 0;
  return (int) ceil((float)(x-1)/h->d);
}
void siftup(heap*h,item *i,int x){
  int p=parent(h,x);
  while((p!=0)&&(h->h[p]->key > i->key)){
    h->h[x]=h->h[p];
    h->h[x]->pos=x;
    x=p;
    p=parent(h,x);
  }
  h->h[x]=i;
  h->h[x]->pos=x;
}

item* insert(heap* h,ll key,int value){
  ++h->size;
  item *res=makeitem(key,value);
  siftup(h,res,h->size);
  return res;
}

#define min2(a,b) ((a)<(b)?(a):(b))
int minchild(heap*h,int x){
  int i,minc;
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

void siftdown(heap*h,item*i,int x){
  int c=minchild(h,x);
  while((c!=0) &&(h->h[c]->key < i->key)){
    h->h[x]=h->h[c];
    h->h[x]->pos=x;
    x=c;
    c=minchild(h,c);
  }
  h->h[x]=i;
  h->h[x]->pos=x;
}

void delete(heap*h,item*i){
  item* j=h->h[h->size];
  if(i->pos !=j->pos){
    if(j->key<=i->key)siftup(h,j,i->pos);
    else siftdown(h,j,i->pos);
  }
  --h->size;
}

void deletemin(heap*h){
  /*item *last=h->h[h->size];
  --h->size;
  if(h->size>0) siftdown(h,last,1);
  */
  delete(h,h->h[1]);
}

heap* makeheap(int maxsize,int d){
  heap* res=malloc(sizeof(heap));
  res->h=malloc(sizeof(item*)*maxsize+10);
  res->size=0;
  res->d=d;
  return res;
}

void freeheap(heap*h){
  free(h->h);
  free(h);
}

void changekey(heap*h,item*i,ll k){
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

#define MAXS 10100
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
void readgraph(){
  fscanf(fi,"%d",&n);
  m=n-1;
  int i,u,v;
  long w;
  for(i=1;i<=m;++i){
    g.v[i].s=0;
  }
  for(i=0;i<n-1;++i){
    fscanf(fi,"%d%d",&u,&v);
    g.v[u].v[g.v[u].s]=1;
    g.v[u].n[g.v[u].s]=v;
    ++g.v[u].s;
    g.v[v].v[g.v[v].s]=1;
    g.v[v].n[g.v[v].s]=u;
    ++g.v[v].s;
  }
}
long res=MAXC;
void dijkstra(int u){
  ll r[n+2];
  int i,j;
  heap *h=makeheap(n,a);
  item* hi[n+2];
  for(i=1;i<=n;++i){
    hi[i]=insert(h,MAXC,i);
  }
  changekey(h,hi[u],0);
  while(h->size>0){
    item *curr=h->h[1];
    r[curr->value]=curr->key;
    deletemin(h);
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
int main(){
#if Test
fi=fopen(f_i,"r");
#else
fi=stdin;
#endif
readgraph();
    return 0;
}

