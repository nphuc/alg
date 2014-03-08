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
int main(){
  ll k,h,res=1;
  scanf("%lld%lld",&k,&h);
  int a[65],n=0;
  while(k){
    a[n++]=k%2;
    k/=2;
  }
  int i;
  for(i=n-1;i>=0;--i){
    printf("%d",a[i]);
  }
  return 0;
}
