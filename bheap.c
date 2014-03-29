#include <stdio.h>
#include <stdlib.h>

typedef struct type{
    long  key;
    int value;
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

#define CMP1(a,b) ((a)->key<=(b)->key)
#define CMP(a,b) ((a)->key<=(b)->key)
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
#include <time.h>
int main(){
    srand(time(NULL));
    long n=100;
    type *t;
    heap h;
    heap_init(&h,120);
    while(n--){
        t=malloc(sizeof(type));
        *t=(type){
            .value=n,
                .key=rand()%100
        };
        heap_push(&h,t);
    }
    while(h.count){
        printf("%d %ld\n",h.data[0]->value,h.data[0]->key);
        heap_pop(&h);
    }
    return 0;
}
