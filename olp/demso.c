#include <stdio.h>
#include <stdlib.h>

#define abs(x) ((x)>0?(x):-(x))
int sodep(int n,int d){
  int a[10],len=0;
  while(n){
    a[len]=n%10;
    n/=10;
    ++len;
  }
  int i,k=0;
  for(i=0;i<len-1;++i){
    if(abs(a[i]-a[i+1])>d)++k;
  }
  return k;
}
int main(){
  int a,b,d,k,i;
  scanf("%d%d%d%d",&a,&b,&d,&k);
  int res=0;
  for(i=a;i<=b;++i){
    if(sodep(i,d)<=k) ++res;
  }
  printf("%d",res);
  return 0;
}
