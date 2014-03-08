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

double pow1(double a,ll n){
  double t=a,r=1;
  while(n!=0){
    if(n%2==1){
      r*=t;
    }
    t=t*t;
    n/=2;
  }
  return r;
}

#define M 111539786
ll solve(ll n){
  double  a=(1+sqrtl(5))/2,b=(1-sqrtl(5))/2;
  double x=(pow1(a,n)-pow1(b,n))/(a-b);
  ll t=x/M;
  return x-M*t;
}
int main(){
  ll n,i,t;
  scanf("%lld",&t);
  for(i=0;i<t;++i){
    scanf("%lld",&n);
    fprintf(stdout,"%lld",solve(n+1));
  }
  return 0;
}
