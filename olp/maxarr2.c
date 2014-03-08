#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
ll get(ll n){
  if(n==0||n==1){
    return n;
  }else{
    if(n%2==0){
      return get(n/2);
    }else{
      return get(n/2)+get(n/2+1);
    }
  }
}
int main(){
  ll i,t,res,n;
  scanf("%lld",&t);
  for(i=0;i<t;++i){
    printf("%3lld:%-4lld",i,get(i));
  }
  return 0;
}
