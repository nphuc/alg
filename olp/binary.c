#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i ""
#define f_o ""
typedef long long ll;
#define maxL 35
ll f[maxL]={1},lastn=0;
ll gt(ll n){
  if(n<=lastn) return f[n];
  for(lastn=lastn+1;lastn<=n;++lastn){
    f[lastn]=f[lastn-1]*lastn;
  }
  return f[n];
}
int countbit(ll n){
  int res=0;
  while(n!=0){
    n >>= 1;
    ++res;
  }
  return res;
}
ll tohop(ll n, ll k){
  
}
int main(){
  printf("%lld",gt(15));
  return 0;
}
