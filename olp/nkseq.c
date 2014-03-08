#include <stdio.h>
#include <stdlib.h>


#define MAXN 100100
long long f[MAXN],
     b[MAXN],
     n;

void line(long long i){
  int j,k;
  for(j=0;j<n;++j){
    if(f[j]<=0) continue;
    k=i+j;
    if(k>=n) k=k-n;
    f[j]=f[j]+b[k];
  }
}
int main(){
  scanf("%lld",&n);
  long long i;
  for(i=0;i<n;++i){
    scanf("%lld",&(b[i]));
    f[i]=b[i];
  }
  for(i=1;i<n;++i){
    line(i);
  }
  long long res=0;
  for(i=0;i<n;++i){
    if(f[i]>0) ++res;
  }
  printf("%lld",res);
  return 0;
}


