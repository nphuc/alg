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
long res=0;
void st(long n,long k){
  long s=n+k,a,b;
  if(s%2==0){
    a=s/2;
    b=n-a;
    if(b>0){
      st(a,k);
      st(b,k);
    }else{
      if(b==0){
        ++res;
      }else{
        st(a,k);
      }
    }
  }else{
    ++res;
  }
}
int main(){
  long a,b;
  scanf("%ld%ld",&a,&b);
  st(a,b);
  printf("%ld",res);
  return 0;
}
