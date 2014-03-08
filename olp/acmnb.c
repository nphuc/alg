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
#define maxN 400100
int a[2*maxN],b[2*maxN];
long n;
ll suma=0,sumb=0;
#define min2(a,b) ((a)<(b)?(a):(b))
void solve(long i){
  if(min2(suma+a[i],sumb)<min2(suma,sumb+b[i])){
    suma+=a[i];
  }else{
    sumb+=b[i];
  }
}
int main(){
  scanf("%ld",&n);
  long i;
  for(i=1;i<=2*n;++i){
    scanf("%d%d",a+i,b+i);
  }
  for(i=1;i<=2*n;++i){
    solve(i);
  }
  printf("%lld",suma+sumb);
  return 0;
}
