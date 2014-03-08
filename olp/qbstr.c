#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i ""
#define f_o ""
#define max 1000
#define max2(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
int main(){
  char x[max],y[max];
  scanf("%s%s",x,y);
  int m=strlen(x),n=strlen(y);
  int L[max][max],i,j,res;
  res=0;
  for(i=0;i<m;++i){
    for(j=0;j<n;++j){
      if(x[i]==y[j]){
        if(i==0 || j==0){
          L[i][j]=1;
        }else{
          L[i][j]=L[i-1][j-1]+1;
        }
      }else{
        L[i][j]=max2(L[i-1][j],L[i][j-1]);
      }
      if(L[i][j]>res) res=L[i][j];
    }
  }
  printf("%d",res);
  return 0;
}
