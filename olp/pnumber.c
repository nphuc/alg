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
#define maxN 200
#define maxV 200100
long p[maxN],n;
void init(){
  p[0]=2;
  p[1]=3;
  n=2;
  long i,t=p[n-1];
  while(p[n-1]<=sqrtl(maxV)){
    ++t;
    i=0;
    while(p[i]<=sqrtl(t)){
      if(t%p[i]==0) goto _next;
      ++i;
    }
    p[n]=t;
    ++n;
_next:;
  }
}
int main(){
  init();
  long i,j,a,b;
  scanf("%ld%ld",&a,&b);
  if( a<2) a=2;
  for(i=a;i<=b;++i){
    j=0;
    while(j<n && p[j]<=sqrtl(i)){
      if(i%p[j]==0) goto _next;
      ++j;
    }
    printf("%ld\n",i);
_next:;
  }
  //for(i=0;i<n;++i) printf("%8ld\n",p[i]);
  return 0;
}
