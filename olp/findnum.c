#include <stdio.h>
#include <stdlib.h>
#define maxN 1010
long p[maxN]={2,3},plen=2;

void init(){
  long t=p[plen-1];
  while(plen<maxN){
    ++t;
    long i=0;
    while(p[i]*p[i]<=t){
      if(t%p[i]==0) goto next;
      ++i;
    }
    p[plen]=t;
    ++plen;
    next:;
  }
}
typedef struct pt{
  int a[12],c[12],n;
}pt;

pt uoc(long n){
  int i=0;
  pt res;
  res.n=0;
  for(;;){
    if(n==1 || i>=plen) break;
    if(n % p[i]==0){
      n=n/p[i];
      if(res.n && res.a[res.n-1]==p[i]){
        ++res.c[res.n-1];
      }else{
        res.c[res.n]=1;
        res.a[res.n]=p[i];
        ++res.n;
      }
    }else{
      ++i;
    }
  }
  return res;
}
int main(){
  init();
  long i;
  pt res;
  for(i=1;i<=1000;++i){
    res=uoc(i);
    int j;
    for(j=0;j<res.n;++j){
      printf("%d %d\n",res.a[j],res.c[j]);
    }
  }
  return 0;
}
