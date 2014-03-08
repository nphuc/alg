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
#define maxV 30100 
#define maxN 90
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
ll gt[100];
int cmp(const void *a,const void *b){
  return *(ll*)a>*(ll*)b?1:*(ll*)a<*(ll*)b?-1:0;
}
int main(){
  init();
  ll i=0,prev=0,a,b;
  scanf("%lld%lld",&a,&b);
  tlen=0;
  for(;;){
    if(b%p[i]==0){
      if(prev!=p[i]){
        t[tlen]=p[i];
        c[tlen]=1;
        ++tlen;
        prev=p[i];
      }else{
        ++c[tlen-1];
      }
      b/=p[i];
    }else{
      ++i;
    }
    if(i>=plen||b==1) break;
  }
  if(i>=plen){
    t[tlen]=b;
    c[tlen]=1;
    ++tlen;
  };
  int j;
  ll tmp;
  int chiahet;
  for(i=1;i<=a;++i){
    tmp=i;
_loop:
    chiahet=0;
    for(j=0;j<tlen;++j){
      if(tmp%t[j]==0){
        ++gt[j];
        tmp/=t[j];
        chiahet=1;
      }
    }
    if(chiahet) goto _loop;
  }
  ll res=1000000000000000;
  for(i=0;i<tlen;++i){
    if(gt[i]/c[i]<res) res=gt[i]/c[i];
  }
  printf("%lld",res);
  return 0;
}
