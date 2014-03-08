#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define f_i ""
#define f_o ""
typedef long long ll;
#define maxN 100100
ll a[maxN],m,n,l[maxN],startOf[maxN];
void init(){
  a[0]=-9999999999999;
  a[n+1]=9999999999999;
  m=1;
  l[n+1]=1;
  startOf[1]=n+1;
}
ll find(ll i){
  ll inf,sup,median,j;
  inf=1;sup=m+1;
  do{
    median=(inf+sup)/2;
    j=startOf[median];
    if(a[j]>a[i]) inf=median;else sup=median;
  }while(inf+1!=sup);
  return startOf[inf];
}
void solve(int d){
  ll i,j,k;
  for(i=n;i>=0;--i){
    j=find(i);
    k=l[j]+1;
    if(k>m){
      m=k;
      startOf[k]=i;
    }else{
      if(a[startOf[k]]+d==a[i]) startOf[k]=i;
    }
    l[i]=k;
  }
}
int main(){
  ll i;
  scanf("%lld",&n);
  for(i=1;i<=n;++i) scanf("%lld",a+i);
  int d;
  ll res=0;
  for(d=1;d<=100;++d){
    init();
    solve(d);
    if(m-2>res){
      res=m-2;
    }
  }
  printf("%lld",res);
  return 0;
}
