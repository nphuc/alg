#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <time.h>
#define f_i ""
#define f_o ""
typedef long long ll;
#define maxN 4294967296
#define maxP 10000
ll p[maxP],plen;
void init(){
  p[0]=2;
  p[1]=3;
  plen=2;
  ll i,t=p[plen-1];
  while(t<=sqrtl(maxN)){
    ++t;
    i=0;
    while(p[i]<=sqrtl(t)){
      if(t%p[i]==0) goto _next;
      ++i;
    }
    p[plen]=t;
    ++plen;
_next:;
  }
}
ll powmod(ll a,ll p,ll m){
  ll res=1,t=a;
  while(p!=0){
    if(p%2==1){
      res=(res*t)%m;
    }
    t=(t*t)%m;
    p/=2;
  }
  return res;
}
int isprime(ll n){
  ll s=0;
  ll m=n-1;
  while(m%2==0){
    m=m/2;
    ++s;
  }
  ll a=rand()%(n-2)+2;
  ll b=powmod(a,m,n);
  if(b%n==1) return 1;
  ll i;
  for(i=0;i<s;++i){
    if(b%n==n-1) return 1;
    b=(b*b)%n;
  }
  return 0;
}
ll near(ll n){
  ll i=n-1;
  while(!isprime(i)) --i;
  return i;
}
int main(){
  //init();
  srand(time(NULL));
  ll t,n,i;
  scanf("%lld",&t);
  for(i=0;i<t;++i){
    scanf("%lld",&n);
    printf("%lld\n",near(n));
  }
  return 0;
}
