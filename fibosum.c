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
#define M 1000000007
typedef struct matrix {
  ll a[2][2];
}matrix;
static inline matrix mulmod(matrix *a ,matrix *b){
  matrix res;
  res.a[0][0]= (a->a[0][0] * b->a[0][0] + a->a[1][0] *b->a[0][1])%M;
  res.a[1][0]= (a->a[0][0] * b->a[1][0] + a->a[1][0] *b->a[1][1])%M;
  res.a[0][1]= (a->a[0][1] * b->a[0][0] + a->a[1][1] *b->a[0][1])%M;
  res.a[1][1]= (a->a[0][1] * b->a[1][0] + a->a[1][1] *b->a[1][1])%M;
  return res;
}
static inline matrix powmod(matrix *a,ll n){
  matrix t=*a,res={.a={{1,0},{0,1}}};
  while(n!=0){
    if(n%2==1){
      res=mulmod(&res,&t);
    }
    t=mulmod(&t,&t);
    n>>=1;
  }
  return res;
}
ll getfibo(ll n){
  if(n==0) return 0;
  --n;
  matrix m={.a={{1,1},{1,0}}};
  matrix res=powmod(&m,n);
  return res.a[0][0];
}
int main(){
  ll n,m;
  ll t,i,j,sum;
  scanf("%lld",&t);
  for(i=0;i<t;++i){
    sum=0;
    scanf("%lld%lld",&n,&m);
    sum=(getfibo(m+2)-getfibo(n+1));
    if(sum>=0) sum=sum%M;
    else sum=(sum+M)%M;
    printf("%lld\n",sum);
  }
  return 0;
}
