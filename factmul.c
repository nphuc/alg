#include <stdlib.h>
#include <stdio.h>

#define M 109546051211
#define B 100000000

typedef long long ll;
typedef struct num{
    ll v[3];
}num;

void output(num *n){
    printf("#1:%lld\n#2:%lld\n#3:%lld\n",n->v[0],n->v[1],n->v[2]);
}

void modM(num *n){
    ll t=0,bm=1;
    int i=2;
    while(i>=0){
        t=(t+bm*n->v[i])%M;
        bm=(bm*B)%M;
        --i;
    }
    //printf("#t=%lld\n",t);
    *n=(num){
        .v={0,t/B,t%B}
    };
}
void mul1(num *a,ll t){
    ll t2=a->v[2]*t,
       t1=a->v[1]*t+t2/B,
       t0=a->v[0]*t+t1/B;
    a->v[2]=t2%B;
    a->v[1]=t1%B;
    a->v[0]=t0%B;
    modM(a);
}
void mul(num *a,num *b){
    ll t2=a->v[2]*b->v[2],t,
       t1=a->v[2]*b->v[1]+a->v[1]*b->v[2],
       t0=a->v[1]*b->v[1]+a->v[0]*b->v[2]+b->v[0]*a->v[2];
    a->v[2]=t2%B;
    t=t1+t2/B;
    a->v[1]=t%B;
    a->v[0]=(t0+t/B)%B;
    //printf("t2=%lld t1=%lld t0=%lld\n",t2,t1,t0);
    modM(a);
}
void powM(num *a,ll p){
    num res={.v={0,0,1}},t=*a;
    while(p){
        if(p%2){
            mul(&res,&t);
        }
        p/=2;
        mul(&t,&t);
    }
    modM(&res);
    *a=res;
}
ll get(num *n){
    return n->v[1]*B+n->v[2];
}
#define X 186583
#define Y 587117
int main(){
    ll i,n;
    scanf("%lld",&n);
    if(n>=Y){
        printf("0");
    }
    num gt={.v={0,0,1}},res={.v={0,0,1}};
    for(i=1;i<=n;++i){
        mul1(&gt,i);
        mul(&res,&gt);
    }
    printf("%lld",get(&res));
    return 0;
} 
