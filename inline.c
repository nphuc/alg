#include <stdio.h>
#include <complex.h>
static inline long long fb(long long n){
  if(n==1 || n==2) return 1;
  return fb(n-1)+fb(n-2);
}
int main(){
  //printf("%lld\n",fb(40));
  long complex  d=1+2I;
  printf("%f %f\n",creal(d),cimag(d));
  return 0;
}
