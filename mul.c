#include <stdio.h>
#include <stdlib.h>

#define BASE 100000000
#define maxN 10010
typedef long long ll;
typedef struct num{
    int h;
    ll v[maxN];
}num;

#define last (maxN-1)
#define max2(a,b) ((a)>(b)?(a):(b))
void add(num *a,num *b,num *res){
    register int ir=last,i,it;
    register ll sodu=0;
    while(i>=a->h &&i >=b->h){
        sodu=a->v[i]+b->v[i]+sodu;
        res->v[i]=sodu%BASE;
        sodu/=BASE;
        --i;
    }
    it=i;
    while(it>=a->h){
        sodu=a->v[it]+sodu;
        res->v[it]=sodu%BASE;
        sodu/=BASE;
        --it;
    }
    it=i;
    while(it>=b->h){
        sodu=b->v[it]+sodu;
        res->v[it]=sodu%BASE;
        sodu/=BASE;
        --it;
    }
    while(sodu){
        res->v[it]=sodu%BASE;
        sodu/=BASE;
        --it;
    }
    res->h=it;
}
void sub(num *a,num *b,num *res){ /*a>=b*/
    register int i=last;
    register ll tmp,memo=0;
    while(i>=b->h){
        tmp=memo+a->v[i]-b->v[i];
        if(tmp<0){
            res->v[i]=tmp+BASE;
            if(memo==0) memo=-1;
        }else{
            res->v[i]=tmp;
            if(memo==-1) memo=0;
        }
        --i;
    }
    while(i>=a->h){
        tmp=memo+a->v[i];
        if(tmp<0){
            res->v[i]=tmp+BASE;
            if(memo==0) memo=-1;
        }else{
            res->v[i]=tmp;
            if(memo==-1) memo=0;
        }
        --i;
    }
    res->h=i;
}
void mul(num *a,num *b,num *res){
    int len=max2(last-a->h,last-b->h);
    ll t;
    if(len==1){
        t=a->v[last]*b->v[last];
        if(t<BASE){
            res->h=last;
            res->v[last]=t;
        }else{
            res->h=last-1;
            res->v[last]=t%BASE;
            res->v[last-1]=t/BASE;
        }
        return;
    }
}
int main(){

}
