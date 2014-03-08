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
#define M 2111992
ll q(ll n,ll k){
  if(n<=k) return n+1;
  ll i;
  ll res=0;
  for(i=1;i<k;++i){
    res=(res+q(n-i,k))%M;
  }
  return res;
}
int main(){
  ll n,k;
  scanf("%lld%lld",&n,&k);
  printf("%lld",q(n,k));
  return 0;
}
