#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef long long ll;
typedef struct type{
    ll  key;
    int value;
}type;

typedef struct bheap{
    long count;
    type ** data;
} bheap;

void heap_init(bheap *h,long msize){
    *h=(bheap){
        .count=0,
            .data=malloc(sizeof(type*)*msize)
    };
}

#define CMP1(a,b) ((a)->key<=(b)->key)
#define CMP(a,b) ((a)->key<=(b)->key)
void heap_push(bheap *h,type* value){
    long index,parent;
    for(index=h->count++;index;index=parent){
        parent=(index-1)>>1;
        if(CMP(h->data[parent],value)) break;
        h->data[index] =h->data[parent];       
    }
    h->data[index]=value;
}
type *heap_pop(bheap *h){
    long index,swap,other;
    type* tmp=h->data[--h->count];
    for(index=0;1;index=swap){
        swap=(index<<1)+1;
        if(swap>=h->count) break;
        other=swap+1;
        if((other<h->count)&&CMP(h->data[other],h->data[swap])){
            swap=other;
        }
        if(CMP(tmp,h->data[swap])) break;
        h->data[index]=h->data[swap];
    }
    h->data[index]=tmp;
}
int heap_find(bheap *h,ll key){
    if(h==NULL) return -1;
    int curr=1;
    while(curr<h->count){
        if(h->data[curr]->key==key){
            return curr;
        }else if(h->data[curr]->key > key){
            curr=2*curr;
        }else{
            curr=2*curr+1;
        }
    }
    return -1;
}
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
    while((p!=0)&&(h->h[p]->key > i->key)){
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

void changekey(heap*h,item*i,long k){
    long ki=i->key;
    i->key=k;
    if(ki!=k){
        if(k<ki) siftup(h,i,i->pos);
        else siftdown(h,i,i->pos);
    }
}
#define MAXE 10010
#define MAXC 9999999999999
long g[MAXE][MAXE];
int m,n;
int count[MAXE];
int target[MAXE];
long vert;
ll hash(char *s){
    ll res=0;
    int i=0;
    while(isalpha(s[i])){
        res=res*27+s[i]-'a';
        ++i;
    }
    return res;
}
typedef struct{
    ll key;
    int value;
}   tnode;
int cmp(const void*a ,const void *b){
    ll d=((tnode*)a)->key-((tnode*)b)->key;
    return d>0?1:d<0?-1:0;
}


ll dijkstra(int u,int v){
    int i,j;
    int a=vert/n;
    if(a<2) a=4;
    ll r[n+2];
    heap *h=makeheap(n,a);
    item *hi[n+2];
    for(i=1;i<=n;++i){
        hi[i]=insert(h,MAXC,i);
    }
    changekey(h,hi[u],0);
    while(h->size>0){
        item *curr=h->h[1];
        r[curr->value]=curr->key;
        //printf("#%d %lld\n",curr->value,curr->key);
        deletemin(h);
        for(j=0;j<count[curr->value];++j){
            int visit=target[j];
            item *dest=hi[visit];
            ll pathCost=curr->key+g[curr->value][visit];
            if(pathCost<dest->key){
                changekey(h,dest,pathCost);
            }
        }
    }
    freeheap(h);
    return r[v];
}
void solve(){
    scanf("%d",&n);
    int i;
    vert=0;
    char start[12],end[12];
    int n1,j,v,c;
    bheap h;
    heap_init(&h,n+2);    
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%s",start);
        scanf("%d",&n1);
        count[i]=0;
        type *st=malloc(sizeof(type));
        st->key=hash(start);
        st->value=i;
        heap_push(&h,st);
        for(j=0;j<n1;++j){
            scanf("%d%d",&v,&c);
            g[i][v]=c;
            target[j]=v;
        }
        count[i]=n1;
        vert+=n1;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%s%s",start,end);
        int ist=heap_find(&h,hash(start)),
            ind=heap_find(&h,hash(end));
        printf("%lld\n",dijkstra(h.data[ist]->value,
                    h.data[ind]->value));
    }
    free(h.data);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
