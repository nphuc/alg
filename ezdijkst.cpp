#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
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
    item* res=(item*)malloc(sizeof(item));
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

void Delete(heap*h,item*i){
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
    Delete(h,h->h[1]);
}

heap* makeheap(int maxsize,int d){
    heap* res=(heap*)malloc(sizeof(heap));
    res->h=(item**)malloc(sizeof(item*)*maxsize+10);
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

typedef  map<int,ll> Edge;

#define MAXS 10010
#define MAXC 99999999
FILE *fi;
Edge g[MAXS];
int count[MAXS];
int edge[MAXS];
int n,m,a;
void readgraph(){
    fscanf(fi,"%d%d",&n,&m);
    register int i;
    a=m/n;
    if(a<2) a=2;
    int u,v,c;
    for(i=1;i<=n;++i){
        count[i]=0;   
        g[i].clear();
    }
    i=m;
    while(i--){
        fscanf(fi,"%d%d%d",&u,&v,&c);
        g[u][v]=c;
    }
}
ll dijkstra(int u,int v){
    ll r[n+2];
    int i,j;
    heap* h=makeheap(n,a);
    item *hi[n+2];
    for(i=1;i<=n;++i){
        hi[i]=insert(h,MAXC,i);
    }
    changekey(h,hi[u],0);
    while(h->size){
        item*curr=h->h[1];
        r[curr->value]=curr->key;
        //printf("%d %lld\n",curr->value,curr->key);
        if(curr->value==v){
            freeheap(h);
            return r[v];
        }
        deletemin(h);
        for(Edge::iterator j=g[curr->value].begin();
                j!=g[curr->value].end();++j){
            int visit=j->first;
            item *dest=hi[visit];
            ll pathCost=curr->key+j->second;
            if(pathCost<dest->key){
                changekey(h,dest,pathCost);
            }
        }
    }
}

int main(){
#ifdef Test
    fi=fopen("ezdijkst.inp","r");
#else
    fi=stdin;
#endif
    int t,u,v;
    fscanf(fi,"%d",&t);
    while(t--){
        readgraph();
        fscanf(fi,"%d%d",&u,&v);
        ll res=dijkstra(u,v);
        if(res>=MAXC){
            printf("NO\n");
        }else{
            printf("%lld\n",res);
        }
    }
    return 0;
}
