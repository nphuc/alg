#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef long ll;
typedef struct item{
    int x,y;
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

static inline item* makeitem(ll key,int x,int y){
    item* res=malloc(sizeof(item));
    *res=(item){
        .key=key,
            .x=x,
            .y=y
    };
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

static inline item* insert(heap* h,ll key,int x,int y){
    ++h->size;
    item *res=makeitem(key,x,y);
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
#define M 102
int n,mt[M][M];
void read(){
    n=getInt();
    register int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            mt[i][j]=getInt();
        }
    }
}
int main(){
    read();
    return 0;
}
