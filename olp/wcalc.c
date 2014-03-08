#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int main(){
  ll b,a,n;
  scanf("%lld%lld",&b,&n);
  ll res=0,d,m1,m2;
  for(a=0;a<=b;++a){ 
    d=floorl(sqrtl(n*n*b*(b-a)));
    if(d*d==n*n*b*(b-a) && d%b==0){
      m1=(-d+b*n)/b;
      m2=(d+b*n)/b;
      printf("%lld %lld %lld %lld\n",a,b,m1,n);
      printf("%lld %lld %lld %lld\n",a,b,m2,n);
    }
  }
  printf("%lld",res);
  return 0;
}
