#include <stdio.h>
#include <stdlib.h>

#define maxN 4000
long p[maxN]={2,3},plen=2;
long max=0;
long a[25],n;

int isprime(long n){
  int i=0;
  while(p[i]*p[i]<=n&&i<plen){
    if(n%p[i]==0) return 0;
    ++i;
  }
  return 1;
}
long solve(long n){
  if(isprime(n)) return n;
  int i=0;
  while(p[i]*p[i]<=n && i<plen){
    if(n%p[i]!=0) goto next;
    long a=n;
    while(a%p[i]==0) a/=p[i];
    if(a==1) return p[i];
next:++i;
  }
  return 1;
}
int main(){
  scanf("%ld",&n);
  long i;
  for(i=0;i<n;++i){
    scanf("%ld",a+i);
    if(a[i]>max) max=a[i];
  }
  long t=p[plen-1];
  while(t*t<=max){
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
  for(i=0;i<n;++i){
    printf("%ld\n",solve(a[i]));
  }
  return 0;
}
