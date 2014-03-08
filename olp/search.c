#include <stdio.h>
#include <stdlib.h>
#define maxN 100100
char a[maxN],b[maxN],c[maxN];
long m,n,p;
int main(){
  scanf("%ld%ld%ld",&m,&n,&p);
  long i,t;
  for(i=0;i<m;++i){
    scanf("%ld",&t);
    a[t]=1;
  }
  for(i=0;i<n;++i){
    scanf("%ld",&t);
    b[t]=1;
  }
  for(i=0;i<p;++i){
    scanf("%ld",&t);
    c[t]=1;
  }
  long res=0;
  for(i=1;i<=100000;++i){
    if(a[i] && c[i] && !b[i])++res;
  }
  printf("%ld",res);
  return 0;
}
