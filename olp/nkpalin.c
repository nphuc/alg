#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i ""
#define f_o ""
#define max 2013
#define max2(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
int L[max][max],i,j,res,t[max][max],m,n;
char x[max],y[max];
int main(){
  scanf("%s",x);
  m=strlen(x),n=m;
  for(i=0;i<m;++i){
    y[i]=x[n-1-i];
  }
  res=0;
  for(i=0;i<m;++i){
    for(j=0;j<n;++j){
      if(x[i]==y[j]){
        if(i==0 || j==0){
          L[i][j]=1;
        }else{
          L[i][j]=L[i-1][j-1]+1;
        }
        t[i][j]=0;
      }else{
        if(L[i-1][j]>=L[i][j-1]){
          L[i][j]=L[i-1][j];
          t[i][j]=1;
        }else{
          L[i][j]=L[i][j-1];
          t[i][j]=-1;
        }
      }
      if(L[i][j]>res) res=L[i][j];
    }
  }
  i=m-1;j=n-1;
  while(i>=0&&j>=0){
    if(t[i][j]==0){
      printf("%c",x[i]);
      --i,--j;
    }else if(t[i][j]==1){
      --i;
    }else{
      --j;
    }
  }
  return 0;
}
