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
#define maxN 26
int map[maxN+1][maxN+1],x[maxN+1],y[maxN+1],cx[maxN+1],cy[maxN+1],xl,yl,n;
void init(){
  int i,j;
  for(i=0;i<=maxN;++i){
    for(j=0;j<=maxN;++j){
      map[j][i]=0;
    }
  }
  for(i=0;i<n;++i){
    map[y[i]][x[i]]=1;
  }
}
int diff(int *a,int n){
  int i,res=0;
  for(i=1;i<n;++i){
    if(*(a+i)-*(a+i-1)!=1){
      ++res;
    }
  }
  return res;
}
int solve(){
  init();
  int i,j,a,b;
  xl=0;yl=0;
  for(j=0;j<=maxN;++j){
    for(i=0;i<=maxN;++i){
      if(map[j][i]) goto next1;
    }
    cy[yl]=j;
    ++yl;
next1:;
  }
  for(i=0;i<=maxN;++i){
    for(j=0;j<=maxN;++j){
      if(map[j][i]) goto next2;
    }
    cx[xl]=i;
    ++xl;
next2:;
  }
  a=diff(cx,xl);
  b=diff(cy,yl);
  return a+b;
}
int main(){
  int i,t,j,r[5];
  scanf("%d",&t);
  for(i=0;i<t;++i){
    scanf("%d",&n);
    for(j=0;j<n;++j){
      scanf("%d%d",x+j,y+j);
    }
    r[i]=solve();
  }
  for(i=0;i<t;++i){
    printf("%d\n",r[i]);
  }
  return 0;
}
