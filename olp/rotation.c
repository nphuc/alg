#include <stdio.h>
#include <stdlib.h>
#define maxN 1010
int sum=0;
int main(){
  int n,a,b,d,i;
  scanf("%d",&n);
  for(i=0;i<n-1;++i){
    scanf("%d%d%d",&a,&b,&d);
    sum+=d;
  }
  printf("%d",sum%2);
  return 0;
}
