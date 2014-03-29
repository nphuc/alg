#include <stdio.h>
#include <stdlib.h>

long solve(int n){
  long res=0;
  while(n){
    res+=n*n;
    --n;
  }
  return res;
}
int main(){
  int t;
  do{
    scanf("%d",&t);
    if(t==0) break;
    printf("%ld\n",solve(t));
  }while(1);
  return 0;
}
