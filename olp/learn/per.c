#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "QBHV.INP"
#define f_o ""
typedef long long ll;
#define max 15
int s[max];
int n;
void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
#define ABS(x) ((x)>0?(x):-(x))
int main(){
  int i,j,k,a,b;
  n;
  int m;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i) s[i]=i+1;
  ll d=0;
  for(;;){
    for(j=0;j<n;++j){
      if(ABS(s[j]-j-1)>m)goto _next;
    }
    ++d;
_next:;
    i=n-2;
    while(i>=0 &&s[i]>=s[i+1])--i;
    if(i<0) break;
    k=n-1;
    while(s[k]<=s[i]) --k;
    swap(s+k,s+i);
    a=i+1;b=n-1;
    while(a<b) {
      swap(a+s,b+s);
      ++a;
      --b;
    }
  }
  printf("%lld",d);
  return 0;
}
