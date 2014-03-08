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
#define maxN 2000
ll a[maxN],d[maxN],n;
#define abs(x) ((x)>=0?(x):-(x))
ll solve(ll st){
  ll i=st+1,d0;
  if(st<n-1){
    d0=abs(a[st+1]-a[st]);
    while(abs(a[i]-a[i-1])==d0 && i<n)++i;
  }
  return i;
}
int main(){
  scanf("%lld",&n);
  ll i,res=0;
  for(i=0;i<n;++i) scanf("%lld",a+i);
  i=0;
  while(solve(i)<n){
    i=solve(i);
    ++res;
  }
  printf("%lld",res);
  return 0;
}
