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
#define maxV 1000000100
#define maxN 4000
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
#define M 20122007
ll powmod(ll a,ll p){
  ll res=1,t=a;
  while(p!=0){
    if(p%2==1){
      res=(res*t)%M;
    }
    t=(t*t)%M;
    p/=2;
  }
  return res;
}
ll powd(ll a,ll p){
  ll res=1,t=a;
  while(p!=0){
    if(p%2==1){
      res=(res*t);
    }
    t=(t*t);
    p/=2;
  }
  return res;
}
ll m[100],res;
void Try(ll i){
  ll d=1,j;
  if(i==tlen){
    for(j=0;j<tlen;++j){
      d=d*powd(t[j],m[j]);
    }
    res=(res*(powmod(3,d)-1))%M;
  }else{
    for(j=0;j<=c[i];++j){
      m[i]=j;
      Try(i+1);
    }
  }
}
int main(){
  init();
  ll n;
  scanf("%lld",&n);
  ll i=0,prev=0;
  tlen=0;
  while(1){
    if(n%p[i]==0){
      if(p[i]!=prev){
        ++tlen;
        t[tlen-1]=p[i];
        c[tlen-1]=1;
        prev=p[i];
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
  res=1;
  Try(0);
  printf("%lld",res);
  return 0;
}
