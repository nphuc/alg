#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define get(a,b,m) ((b)/(m)-(a)/(m)+((a)%m==0))
#define solve(a,b) (get(a,b,12)+get(a,b,30)-2*get(a,b,60))
int main(){
  ll t,i,a,b;
  scanf("%lld",&t);
  for(i=0;i<t;++i){
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",solve(a,b));
  }
  return 0;
}
