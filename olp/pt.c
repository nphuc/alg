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
#define maxV 1000000000000
#define maxN 90000
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
ll t[100],c[100],tlen;
int cmp(const void *a,const void *b){
  return *(ll*)a>*(ll*)b?1:*(ll*)a<*(ll*)b?-1:0;
}
int main(){
  init();
  ll n;
  ll tmp,mx=0,memo=0;
  //scanf("%lld",&tmp);
  //for(n=2;n<=tmp;++n){
    scanf("%lld",&n);
    ll i=0,*v;
    tlen=0;
    while(1){
      if(n%p[i]==0){
        v=bsearch(p+i,t,tlen,sizeof(ll),cmp);
        if(v==NULL){
          ++tlen;
          t[tlen-1]=p[i];
          c[tlen-1]=1;
        }else{
          ++c[tlen-1];
        }
        n/=p[i];
      }else{
        ++i;
      }
      if(i>=plen|| n==1) break;
    }
    if(i>=plen){
      t[tlen]=n;
      ++c[tlen];
      ++tlen;
    }
    if(tlen>mx) {
      mx=tlen;
      memo=n;
    }
    for(i=0;i<tlen;++i){
      printf("%lld %lld\n",t[i],c[i]);
    }
  //}
  printf("%lld",tlen);
  return 0;
}
