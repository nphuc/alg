#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define C 18
#if C==18
#define BASE 1000000000000000000
#else
#undef C
#define C 9
#define BASE 1000000000
#endif

typedef long long ll;
typedef struct num{
  ll a[2];
}num;
void p(const num *a){
  if(a->a[0]!=0){
    printf("%lld",a->a[0]);
    printf("%018lld",a->a[1]);
  }else{
    printf("%lld",a->a[1]);
  }
  printf("\n");
}
num add(const num *a,const num *b){
  num res;
  ll a0=a->a[0]+b->a[0];
  ll a1=a->a[1]+b->a[1];
  res.a[0]=a0+a1/BASE;
  res.a[1]=a1%BASE;
  return res;
}
num mul1(const num *a,ll n){
  num res;
  ll a0=a->a[0]*n;
  ll a1=a->a[1]*n;
  res.a[0]=a0+a1/BASE;
  res.a[1]=a1%BASE;
  return res;
}
num treenum(ll i){
  num res,t;
  res.a[0]=0;
  res.a[1]=0;
  t.a[0]=0;
  t.a[1]=1;
  while(i!=0){
    if(i%2==1){
      res=add(&res,&t);
    }
    t=mul1(&t,3);
    i/=2;
  }
  return res;
}
int main(){
  ll i,t,n;
  num r;
  //FILE *fi=fopen("TREENUM.INP","r");
  FILE *fi=stdin;
  fscanf(fi,"%lld",&t);
  for(i=0;i<t;++i){
    fscanf(fi,"%lld",&n);
    r=treenum(n);
    p(&r);
  }
  return 0;
}
