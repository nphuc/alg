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
  long k,i,n,t;
  scanf("%ld",&k);
  for(i=0;i<k;++i){
    scanf("%ld",&n);
    t=1;
    for(i=0;i<n;++i){
      fprintf(stdout,"%ld",t);
      ++t;
      if(t>9) t=0;
    }
    --t;
    for(i=0;i<n-1;++i){
      --t;
      if(t<0) t=9;
      fprintf(stdout,"%ld",t);
    }
    fprintf(stdout,"\n");
  }
  return 0;
}
