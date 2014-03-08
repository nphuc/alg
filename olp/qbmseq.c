#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define f_i ""
#define f_o ""
typedef long long ll;
#define maxN 10100
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
    if(a[j]>=a[i]) inf=median;else sup=median;
  }while(inf+1!=sup);
  return startOf[inf];
}
void solve(){
  ll i,j,k;
  for(i=n;i>=0;--i){
    j=find(i);
    k=l[j]+1;
    if(k>m){
      m=k;
      startOf[k]=i;
    }else{
      if(a[startOf[k]]<=a[i]) startOf[k]=i;
    }
    l[i]=k;
  }
}
int check(ll n){
  ll c2=(ll) sqrt(8*n+1);
  if((c2*c2==(8*n+1)) && (c2-1)%2==0){
    return 1;
  }
  return 0;
}
int main(){
  ll i;
  ll inl;
  n=0;
  scanf("%lld",&inl);
  for(i=1;i<=inl;++i) {
    scanf("%lld",a+n+1);
    if(check(a[n+1])){
      ++n;
      //printf("a=%lld\n",a[n]);
    }
  }
  init();
  solve();
  ll res=1,max=0;
  for(i=1;i<m-1;++i){
    if(startOf[i]-startOf[i+1]==1){
      //printf("s[%lld]=%lld\n",i,startOf[i]);
      ++res;
    }else{
      if(res>max) max=res;
      res=1;
    }
  }
  if(res>max) max=res;
  printf("%lld",max);
  return 0;
}
