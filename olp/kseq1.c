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
#define maxN 310
long a[maxN],n,k=0;
void solve(long i){
  long k_,j;
  for(k_=1;i+2*k_<=n;++k_){
      for(j=1;j<=k_;++j){
        if(a[i+j]>=a[i+k_+j]) goto _next;
      }
      if(k_>k) k=k_;
_next:;
  }
}
int main(){
  scanf("%ld",&n);
  long i;
  for(i=1;i<=n;++i){
    scanf("%ld",a+i);
  }
  for(i=1;i<=n;++i) solve(i);
  printf("%ld",k);
  return 0;
}
