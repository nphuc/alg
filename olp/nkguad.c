#include <stdio.h>
#include <stdlib.h>

long map[710][710];
#define max2(a,b) ((a)>(b)?(a):(b))
#define max4(a,b,c,d) max2(max2(a,b),max2(c,d))
int main(){
  long m,n;
  scanf("%ld%ld",&m,&n);
  long i,j;
  for(j=1;j<=m;++j){
    for(i=1;i<=n;++i){
      scanf("%ld",map[j]+i);
    }
  }
  long res=0;
  for(j=1;j<=m;++j){
    for(i=1;i<=n;++i){
      if(map[j][i]>max4(map[j-1][i],map[j+1][i],map[j][i+1],map[j][i-1])){
        ++res;
      }
    }
  }
  printf("%ld",res);
  return 0;
}
