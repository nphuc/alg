#include <stdio.h>
#include <stdlib.h>

#define max 10000100

long powmod(long a,long p,long m){
  long res=1,t=a;
  while(p!=0){
    if(p%2){
      res=(res*t)%m;
    }
    t=(t*t)%m;
    p/=2;
  }
  return res;
}
long divmod(long a,long b,long m){
  // if m is prime number (a/b) %m = ((a*b % m)*(b^-1 %m)) %m
  // b^-1 %m =b^(m-2) %m
  return ((a%m)*powmod(b,m-2,m))%m;
}
int main(){
  printf("%ld\n",divmod(100,3,5));
}
