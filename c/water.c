#include <stdio.h>
#include <stdlib.h>

typedef struct type{
    int x,y,t;
    long h,orig_h;
    struct type *p;
}type;

typedef struct heap{
    long count;
    type ** data;
} heap;

void heap_init(heap *h,long msize){
    *h=(heap){
        .count=0,
            .data=malloc(sizeof(type*)*msize)
    };
}

#define CMP(a,b) ((a)->h<=(b)->h)

void heap_push(heap *h,type* value){
    long index,parent;
    for(index=h->count++;index;index=parent){
        parent=(index-1)>>1;
        if(CMP(h->data[parent],value)) break;
        h->data[index] =h->data[parent];       
    }
    h->data[index]=value;
}
type *heap_pop(heap *h){
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
long getLong(){
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
type **map;
void solve(int n,int m){
    map=malloc((m+5)*(n+5)*sizeof(type**));
    type** bfs=malloc((m+5)*(n+5)*sizeof(type**));
    int i,j;
    heap h;
    heap_init(&h,(m+5)*(n+5));
    for(j=0;j<=n+1;++j){
        for(i=0;i<=m+1;++i){
            if(i>0 &&i<=n &&j>0 &&j<=m){
                long in=getLong();
               map[j][i]=(type){
                .x=0,
                    .y=0,
                    .t=0,
                    .p=&map[j][i],
                    .orig_h=in,
                    .h=in
               };
            }else{
                map[j][i].t=0;
                map[j][i].p=&map[0][0];
            }
        }
    }
    long res=0,t=0;
    while(h.count){
        t++;
        type *s=h.data[0];
        heap_pop(&h);
        if(s!=s->p) continue;
        s->t=t;
        int b=0,e=0;
        bfs[0]=s;
    }
}
int main(){
    return 0;
}
