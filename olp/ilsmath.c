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
typedef long double ld;
ll res[200],rlen=0;
int main(){
  ll n,i=1;
  ld prev=0;
  ld log10=log(10);
  scanf("%lld",&n);
  while(floorl(prev+1)<=n){
    prev+=log((ld)i)/log10;
    if((ll)floorl(prev+1)==n){ res[rlen]=i;++rlen;} 
    ++i;
  }
  if(!rlen){
     printf("NO");
  }else{
    printf("%lld\n",rlen);
    for(i=0;i<rlen;++i){
      printf("%lld ",res[i]);
    }
  }
  return 0;
}
