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
#define max 1000100
ll a[max],n,d[max];
int main(){
  scanf("%lld",&n);
  ll i,sum=0;
  for(i=0;i<n;++i){
    scanf("%lld",a+i);
    sum+=a[i];
  }
  return 0;
}
