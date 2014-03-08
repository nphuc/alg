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
  ll prev=1,len=1,n=1;
  ll t;
  scanf("%lld",&t);
  while(len<t){
    ++n;
    prev=(prev/n+1)*n+n*(n-1);
    len+=n;
  }
  prev=prev-n*(len-t);
  printf("%lld",prev);
  return 0;
}
