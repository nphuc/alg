#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    long value;
    long key;
    long pos;
} item;

typedef struct heap{
    long size;
    item **h;
    int d;
}heap;

static inline item* findmin(heap* h){
    if(h->size==0)return NULL;
    return h->h[1];
}

static inline item* makeitem(long key,long value){
    item* res=malloc(sizeof(item));
    res->key=key;
    res->value=value;
    return res;
}
static inline long parent(heap* h,long x){
    if (x==1) return 0;
    return (long) ceil((float)(x-1)/h->d);
}
static inline void siftup(heap*h,item *i,long x){
    long p=parent(h,x);
    while((p!=0)&&GT(h->h[p]->key , i->key)){
        h->h[x]=h->h[p];
        h->h[x]->pos=x;
        x=p;
        p=parent(h,x);
    }
    h->h[x]=i;
    h->h[x]->pos=x;
}

static inline item* insert(heap* h,long key,long value){
    ++h->size;
    item *res=makeitem(key,value);
    siftup(h,res,h->size);
    return res;
}

#define min2(a,b) ((a)<(b)?(a):(b))
static inline long minchild(heap*h,long x){
    register long i,minc;
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
static inline void siftdown(heap*h,item*i,long x){
    long c=minchild(h,x);
    while((c!=0) &&LT(h->h[c]->key , i->key)){
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
        if(LE(j->key,i->key))siftup(h,j,i->pos);
        else siftdown(h,j,i->pos);
    }
    --h->size;
}

static inline void deletemin(heap*h){
    delete(h,h->h[1]);
}

static inline heap* makeheap(long maxsize,int d){
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

static inline void changekey(heap*h,item*i,long k){
    long ki=i->key;
    i->key=k;
    if(ki!=k){
        if(LT(k,ki)) siftup(h,i,i->pos);
        else siftdown(h,i,i->pos);
    }
}
#include <time.h>

void printitem(item* i){
    printf("#item: %ld %ld \n",i->value,i->key);
}
static inline long getLong(){
    long res=0;
    char c;
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
char *a;

int main(){
    long n=getLong();
    a=malloc(n*sizeof(char));
    register long i,c=0;
    heap *h;
    int ary=log(n)/log(4);
    if(ary<4) ary=4;
    h=makeheap(n,ary);
    item **hi=malloc(sizeof(item)*n);
    for(i=0;i<n;++i){
        hi[i]=insert(h,getLong(),i);
        a[i]=1;
    }
    while(h->size){
        item *min=h->h[1];
        delete(h,min);
        a[min->value]=0;
        if(min->value>0 && a[min->value-1]){
            delete(h,hi[min->value-1]);
            a[min->value-1]=0;
        }
        if(min->value<n-1 && a[min->value+1]){
            delete(h,hi[min->value+1]);
            a[min->value+1]=0;
        }
        ++c;
    }
    printf("%ld",c);
    return 0;
}
