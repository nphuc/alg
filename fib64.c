#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i ""
#define f_o ""
typedef long long ll;
#define maxT 200
typedef struct matrix {
    ll a[2][2];
}matrix;
ll M;
ll mul_mod(ll a, ll b, ll m)
{
   ll d = 0, mp2 = m >> 1;
   register int i;
   if (a >= m) a %= m;
   if (b >= m) b %= m;
   for (i = 0; i < 64; ++i)
   {
       d = (d > mp2) ? (d << 1) - m : d << 1;
       if (a & 0x8000000000000000ULL)
           d += b;
       if (d > m) d -= m;
       a <<= 1;
   }
   return d;
}
matrix mulmod(matrix *a ,matrix *b){
    matrix res;
    res.a[0][0]= (mul_mod(a->a[0][0] ,b->a[0][0],M) + mul_mod(a->a[1][0] ,b->a[0][1],M))%M;
    //res.a[1][0]= (a->a[0][0] * b->a[1][0] + a->a[1][0] *b->a[1][1])%M;
    res.a[1][0]= (mul_mod(a->a[0][0] ,b->a[1][0],M) + mul_mod(a->a[1][0] ,b->a[1][1],M))%M;
    //res.a[0][1]= (a->a[0][1] * b->a[0][0] + a->a[1][1] *b->a[0][1])%M;
    res.a[0][1]= (mul_mod(a->a[0][1] ,b->a[0][0],M) + mul_mod(a->a[1][1] ,b->a[0][1],M))%M;
    //res.a[1][1]= (a->a[0][1] * b->a[1][0] + a->a[1][1] *b->a[1][1])%M;
    res.a[1][1]= (mul_mod(a->a[0][1] ,b->a[1][0],M) + mul_mod(a->a[1][1] ,b->a[1][1],M))%M;
    return res;
}
matrix powmod(matrix *a,ll n){
    matrix t=*a,res={.a={{1,0},{0,1}}};
    while(n!=0){
        if(n%2==1){
            res=mulmod(&res,&t);
        }
        t=mulmod(&t,&t);
        n/=2;
    }
    return res;
}
int main(){
    ll n;
    matrix one,res;
    long i,test=1000;
    for(i=0;i<test;++i){
        scanf("%lld%lld",&n,&M);
        if(n<2){
            printf("%lld\n",n);
            continue;
        }
        one.a[0][0]=1;
        one.a[1][0]=1;
        one.a[0][1]=1;
        one.a[1][1]=0;
        res=powmod(&one,n-1);
        printf("%lld\n",res.a[0][0]);
    }
    return 0;
}
