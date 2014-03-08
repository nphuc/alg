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
long songuoc(long n){
  int i,a[10],len;
  len=0;
  while(n!=0){
    a[len]=n%10;
    ++len;
    n/=10;
  }
  long res=0;
  for(i=0;i<len;++i){
    res=res*10+a[i];
  }
  return res;
}
long ucln(long a,long b){
  long t;
  while(b!=0){
    t=a%b;
    a=b;
    b=t;
  }
  return a;
}
int main(){
  long a,b,i,c=0;
  scanf("%ld%ld",&a,&b);
  for(i=a;i<=b;++i){
    if(ucln(i,songuoc(i))==1)++c;
  }
  printf("%ld",c);
  return 0;
}
