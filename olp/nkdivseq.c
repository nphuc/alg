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
  ll prev=1,len=1,n=2,mlen=1;
  ll t;
  scanf("%lld",&t);
  while(len!=t){
    prev=(prev/n+1)*n;
    ++len;
    if((len-mlen)%n==0){
      ++n;
      mlen=len;
    }
  }
  printf("%lld",prev);
  return 0;
}
