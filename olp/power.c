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
typedef long double ld;
ll powm(ll a,ll p){
  ll t=a,res=1;
  while(p){
    if(p){
      res*=t;
    }
    p/=2;
    t*=t;
  }
  return res;
}
ll solve(ll a,ll b){
  ll res=1;

}
int main(){
  return 0;
}
