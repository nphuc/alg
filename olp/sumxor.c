#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  scanf("%d",&n);
  int i,s=1;
  for(i=2;i<=n;++i){
    s^=i;
  }
  printf("%d",s);
  return 0;
}
