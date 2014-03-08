#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "COUNTCBG.INP"
#define f_o ""
typedef long long ll;
long solve(ll n){
  long i,a,c=0;
  for(i=2;i<=sqrtl(2*n);++i){
    a=n-i*(i-1)/2;
    if(a%i==0 && a>=0){
      ++c;
    }
  }
  return c;
}
long r[120],nlen;
int main(){
  ll t;
  //FILE *fi=fopen(f_i,"r");
  FILE *fi=stdin;
  while(fscanf(fi,"%lld",&t)==1) {
    r[nlen]=solve(t);
    ++nlen;
  }
  long i;
  for(i=0;i<nlen;++i)printf("%ld\n",r[i]);
  return 0;
}
