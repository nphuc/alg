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
#define M 111539786
typedef struct matrix {
  ll a[2][2];
}matrix;
matrix mulmod(matrix *a ,matrix *b){
  matrix res;
  res.a[0][0]= (a->a[0][0] * b->a[0][0] + a->a[1][0] *b->a[0][1])%M;
  res.a[1][0]= (a->a[0][0] * b->a[1][0] + a->a[1][0] *b->a[1][1])%M;
  res.a[0][1]= (a->a[0][1] * b->a[0][0] + a->a[1][1] *b->a[0][1])%M;
  res.a[1][1]= (a->a[0][1] * b->a[1][0] + a->a[1][1] *b->a[1][1])%M;
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
  int i,test;
  scanf("%d",&test);

  for(i=0;i<test;++i){
    scanf("%lld",&n);
    if(n<0) break;
    one.a[0][0]=1;
    one.a[1][0]=1;
    one.a[0][1]=1;
    one.a[1][1]=0;
    res=powmod(&one,n);
    printf("%lld\n",res.a[0][0]);
  }
  return 0;
}
