#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#define maxD 15
typedef struct nghiem{
  int n;
  double a[maxD];
}nghiem;
double f(const nghiem *n,double x){
  double res=0;
  int i;
  for(i=0;i<=n->n;++i){
    res=res*x+n->a[i];
  }
  return res;
}
double df(const nghiem*n,double x){
  double res=0;
  int i;
  for(i=0;i<n->n;++i){
    res=res*x+n->a[i]*(n->n-i);
  }
  return res;
}
nghiem dh(const nghiem *n){
  nghiem res;
  res.n=n->n-1;
  int i;
  for(i=0;i<=res.n;++i){
    res.a[i]=n->a[i]*(n->n-i);
  }
  return res;
}
#define L 0.000001
nghiem nhiphan(const nghiem *hs,double VT,double VP){
  double f1=f(hs,VT),
         f2=f(hs,VP);
  nghiem res;
  double t;
  if(f1*f2>0){
    res.n=0;
  }else{
    while(VP-VT>L){
      t=f(hs,(VT+VP)/2);
      if(t*f1<=0){
        VP=(VT+VP)/2;
      }else{
        VT=(VT+VP)/2;
      }
    }
    res.a[0]=VT;
    res.n=1;
  }
  return res;
}
nghiem gpt(const nghiem *hs){
  nghiem r;
  if(hs->n==1){
    r.n=1;
    r.a[0]=-hs->a[1]/hs->a[0];
    return r;
  }
  printf("dh bac=%d\n",hs->n-1);

  int i;
  double T[maxD+2];
  nghiem dfx=dh(hs);
  for(i=0;i<=dfx.n;++i){
    printf("%lf ",dfx.a[i]);
  }
  printf("\n");

  nghiem ct=gpt(&dfx);
  T[0]=-5000;T[ct.n+2]=5000;
  for(i=0;i<=ct.n;++i){
    T[i+1]=ct.a[i];
  }
  nghiem x1;
  for(i=1;i<=ct.n+2;++i){
    x1=nhiphan(hs,T[i-1],T[i]);
    if(x1.n){
      r.a[r.n]=x1.a[0];
      ++r.n;
    }
  }
  return r;
}
int main(){
  nghiem res;
  nghiem hs;
  scanf("%d",&(hs.n));
  int i;
  for(i=0;i<=hs.n;++i){
    scanf("%lf",hs.a+i);
  }
  res=gpt(&hs);
  for(i=0;i<res.n;++i){
    printf("%lf\n",res.a[i]);
  }
  return 0;
}
