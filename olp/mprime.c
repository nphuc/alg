#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define maxP 40000
ll p[maxP],plen;
ll ghep(ll a,ll b){
  ll t=b;
  while(t){
    t/=10;
    a*=10;
  }
  return a+b;
}
void init(){
  p[0]=2;
  p[1]=3;
  plen=2;
  ll t=p[plen-1];
  while(plen<maxP){
    ++t;
    ll i=0;
    while(p[i]*p[i]<=t){
      if(t%p[i]==0){
        goto next1;
      }
      ++i;
    }
    p[plen]=t;
    ++plen;
next1:;
  }
}
int isprime(ll a){
  int i=0;
  while(p[i]*p[i]<=a){
    if(a%p[i]==0) return 0;
    ++i;
  }
  return 1;
}
ll g[maxP],glen;
void initg(){
  glen=0;
  ll pi=0;
  do{
    ll t=ghep(p[pi],p[pi+1]);
    if(isprime(t)){
      g[glen]=t;
      ++glen;
    }
    pi+=2;
  }while(glen<500);
}
int main(){
  init();
  initg();
  int n;
  scanf("%d",&n);
  printf("%lld",g[n-1]);
  return 0;
}
 
