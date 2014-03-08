#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
typedef long long ll;
/*
#define f_i ""
#define f_o ""
int a[30],n;
int cmp(const void *a,const void *b){
  return *(int*)b-*(int*)a;
}
ll ton(){
  int i;
  ll res=0,t=1;
  for(i=n-1;i>=0;--i){
    res+=a[i]*t;
    t*=10;
  }
  return res;
}
#define max 33
long i;
ll f[max];
void toa(){
  ll t=ton();
  f[i]=t;
  t*=2;
  n=0;
  while(t!=0){
    a[n]=t%10;
    t/=10;
    ++n;
  }
  qsort(a,n,sizeof(int),cmp); 
  while(n>0 && a[n-1]==0) --n;
  int i,tmp;
  for(i=0;i<n/2;++i) {
    tmp=a[i];
    a[i]=a[n-i-1];
    a[n-i-1]=tmp;
  }
}*/
long f[]={0,1,2,4,8,16,23,46,29,58,116,223,446,289,578,1156,1223,2446,2489,4789,5789,11578,12356,12247,24449,48889,77789,155578,111356,122227,244445,48889,77789};
int main(){
  long in;
  scanf("%ld",&in);
  if(in<=26){
    printf("%ld",f[in]);
  }else{
    printf("%ld",f[(in-26)%6+26]);
  }
  return 0;
}
