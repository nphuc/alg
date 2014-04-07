#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define _max_heap
#ifndef _max_heap 

#define LT(a,b) ((a)<(b))
#define LE(a,b) ((a)<=(b))
#define GT(a,b) ((a)>(b))
#define GE(a,b) ((a)>=(b))

#else
#define LT(a,b) ((a)>(b))
#define LE(a,b) ((a)>=(b))
#define GT(a,b) ((a)<(b))
#define GE(a,b) ((a)<=(b))

#endif
typedef struct item{
    int value;
    long key;
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

item* makeitem(long key,int value){
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
    while((p!=0)&&GT(h->h[p]->key , i->key)){
        h->h[x]=h->h[p];
        h->h[x]->pos=x;
        x=p;
        p=parent(h,x);
    }
    h->h[x]=i;
    h->h[x]->pos=x;
}

item* insert(heap* h,long key,int value){
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
        if(LT(h->h[i]->key, h->h[minc]->key)){
            minc=i;
        }
        ++i;
    }
    return minc;
}

void siftdown(heap*h,item*i,int x){
    int c=minchild(h,x);
    while((c!=0) &&LT(h->h[c]->key , i->key)){
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
        if(LE(j->key,i->key))siftup(h,j,i->pos);
        else siftdown(h,j,i->pos);
    }
    --h->size;
}

void deletemin(heap*h){
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

void changekey(heap*h,item*i,long k){
    long ki=i->key;
    i->key=k;
    if(ki!=k){
        if(LT(k,ki)) siftup(h,i,i->pos);
        else siftdown(h,i,i->pos);
    }
}

#define MAXS 1010
#define MAXC 99999999
#define MINC (-1000000)
typedef struct edge{
    int v[MAXS];
    int n[MAXS];
    int s;
}edge;
typedef struct graph{
    edge v[MAXS];
}graph;
long a[MAXS];
int n,m,ary;
//graph g;
int cmp(const void *a,const void *b){
    return *(long*)a>*(long*)b?1:
        *(long*)a<*(long*)b?-1:0;
}
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
typedef long ll;
/*static inline long dijkstra(int u){
  ll r[n+2];
  register int i,j;
  heap *h=makeheap(n,ary);
  item* hi[n+2];
  for(i=0;i<n;++i){
  hi[i]=insert(h,MINC,i);
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
  if(pathCost>dest->key){
  changekey(h,dest,pathCost);
  }
  }
  }
  long res=0;
  for(i=0;i<n;++i){
//printf("%ld ",r[i]);
if(r[i]>res) res=r[i];
}
//printf("\n");
return res;
} */   
long rs[MAXS];
#define max2(a,b) ((a)>(b)?(a):(b))
static inline void read(){
    n=getInt();
    long m=1;
    register int i,j,k;
    for(i=0;i<n;++i) {
        a[i]=getLong();
        rs[i]=1;
    }
    qsort(a,n,sizeof(long),cmp);
    rs[0]=1;rs[1]=1;
    for(k=2;k<n;++k){
        i=0;
        j=k-1;
        while(i<j){
            while(i<j &&(a[i]+a[j]!=a[k])){
                if(a[i]+a[j]>a[k]){
                    --j;
                }else{
                    ++i;
                }
            }
            if(a[i]+a[j]==a[k] &&i!=j){
                rs[k]=max2(rs[k],max2(rs[i]+1,rs[j]+1));
                ++i;
                --j;
            }
        }
        if(rs[k]>m) m=rs[k];
    }
    printf("%ld",m);
}
int main(){
    read();
    return 0;
}
