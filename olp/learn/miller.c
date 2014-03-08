#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned long long llu;
llu powm(llu a,llu p,llu m){
  llu res=1,t=a;
  while(p!=0){
    if(p%2==1){
      res=(res*t)%m;
    }
    p/=2;
    t=(t*t)%m;
  }
  return res;
}
int miller(llu n){
  llu s=0,m=n-1;
  while(m%2==0){
    m=m/2;
    ++s;
  }
  llu a=rand()%(n-2)+2;
  llu b=powm(a,m,n);
  if(b==1) return 1;
  llu k;
  for(k=0;k<s;++k){
    if((b+1)%n==0) return 1;
    b=(b*b)%n;
  }
  return 0;
}
#define CHECK 50
int isprime(llu n){
  int res=0;
  int i,t;
  for(i=0;i<CHECK;++i){
    res=res || miller(n);
  }
  return res;
}
int main(){
  srand(time(NULL));
  llu n;
  scanf("%llu",&n);
  printf("%d",isprime(n));
}
