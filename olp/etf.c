#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i "ETF.INP"
#define f_o ""
typedef long long ll;
#define maxV 1000100
#define maxN 200
ll p[maxN],plen;
void init(){
  plen=2;
  p[0]=2;
  p[1]=3;
  ll i, t=p[plen-1];
  while(t<=sqrtl(maxV)){
    ++t;
    i=0;
    while(p[i]<=sqrtl(t)){
      if(t%p[i]==0) goto _next1;
      ++i;
    }
    p[plen]=t;
    ++plen;
_next1:;
  }
}
int cmp(const void *a,const void *b){
  return *(ll*)a>*(ll*)b?1:*(ll*)a<*(ll*)b?-1:0;
}
int main(){
  init();
  ll n,T;
  ll tmp,mx=0,memo=0;
  //FILE *fi=fopen(f_i,"r");
  FILE *fi=stdin;
  fscanf(fi,"%lld",&T);
  ll cnt,res,prev;
  for(cnt=0;cnt<T;++cnt){
    fscanf(fi,"%lld",&n);
    res=n;
    prev=0;
    ll i=0,*v;
    while(1){
      if(n%p[i]==0){
        if(p[i]!=prev){
          prev=p[i];
          res=res*(prev-1)/prev;
        }
        n/=prev;
      }else{
        ++i;
      }
      if(i>=plen|| n==1) break;
    }
    if(i>=plen){
      res=res*(n-1)/n;
    }
    printf("%lld\n",res);
  }
  return 0;
}
