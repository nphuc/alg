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
#define max (20*20*40+120)
long sum[max];
int main(){
  int s1,s2,s3;
  int i,j,k;
  scanf("%d%d%d",&s1,&s2,&s3);
  for(i=0;i<=s1+s2+s3;++i) sum[i]=0;
  long res=0,mx=0;
  for(i=1;i<=s1;++i){
    for(j=1;j<=s2;++j){
      for(k=1;k<=s3;++k){
        ++sum[i+j+k];
        if(sum[i+j+k]>mx) {
          mx=sum[i+j+k];
          res=i+j+k;
        }
      }
    }
  }
  printf("%ld",res);
  return 0;
}
