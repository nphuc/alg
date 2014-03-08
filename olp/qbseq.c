#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i ""
#define f_o ""
#define maxN 1010
#define maxK 55
typedef long long ll;
ll x[maxN+1],
   n,k,
   f[maxN+1][maxK+1];
ll sub(ll a,ll b){
  ll r=a-b;
  if(r<0) r+=k;
  return r%k;
}
void solve(){
  ll i,j;
  for(i=0;i<=n;++i) f[0][i]=maxN;
  f[0][0]=0;
  ll t;
  for(j=1;j<=n;++j){
    for(i=0;i<k;++i){
      t=f[j-1][sub(i,x[j])]+1;
      if(f[j-1][i]<t) {
        f[j][i]=f[j-1][i];
      }else{
        f[j][i]=t;
      }
    }
  }
}
int main(){
  ll i,sum=0;
  scanf("%lld%lld",&n,&k);
  for(i=1;i<=n;++i){
    scanf("%lld",x+i);
    sum=(sum+x[i])%k;
  }
  solve();
  ll t;
  /*
  t=sum%k;
  for(i=n;i>0;--i){
    if(f[i][t]==f[i-1][t]){
      printf("%4lld",x[i]);
    }else{
      t=sub(t,x[i]);
    }
  }
  printf("\n");
  */
  t=sum%k;
  fprintf(stdout,"%lld",n-f[n][t]);
  return 0;
}
