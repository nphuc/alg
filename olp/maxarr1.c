#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
#define maxN 100100
ll a[maxN]={0,1};
ll max[maxN]={0,1};
void init(){
  ll i;
  for(i=2;i<=100000;++i){
    if(i%2==0){
      a[i]=a[i/2];
    }else{
      a[i]=a[i/2]+a[i/2+1];
    }
    if(a[i]>max[i-1]) max[i]=a[i];else max[i]=max[i-1];
  }
}
int main(){
  ll t,i,n;
  init();
  scanf("%lld",&t);
  for(i=0;i<t;++i){
    scanf("%lld",&n);
    printf("%lld\n",max[n]);
  }
  return 0;
}
