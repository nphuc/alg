#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
#define MAX 100000000
#define maxP 40000000
ll p[maxP],plen;

void init(){
  p[0]=2;
  p[1]=3;
  plen=2;
  ll i,t=p[plen-1];
  while(t*t<=MAX){
    ++t;
    i=0;
    while(p[i]*p[i]<=t){
      if(t%p[i]==0) goto next;
      ++i;
    }
    p[plen]=t;
    ++plen;
next:;
  }
  ll tt=plen;
  do{
    ++t;
    i=0;
    while(p[i]*p[i]<=t && i<tt){
      if(t%p[i]==0) goto next2;
      ++i;
    }
    p[plen]=t;
    ++plen;
next2:;
  }while(t<MAX);
}
int main(){
  init();
  return 0;
}
