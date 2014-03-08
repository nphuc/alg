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
#define maxN 1000100
long a[maxN],n;
int main(){
  scanf("%ld",&n);
  long i;
  ll res=0;
  for(i=0;i<n;++i) scanf("%ld",a+i);
  i=0;
  a[n]=0;
  while(i<n){
    if(a[i]>a[i+1]){
      res+=a[i]-a[i+1];
      i+=2;
    }else{
      ++i;
    }
  }
  printf("%lld",res);
  return 0;
}
