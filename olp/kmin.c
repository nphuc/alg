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
#define maxN 50100
ll a[maxN],b[maxN],m,n,k;
int cmp(const void *a,const void *b){
  ll d=*(ll*)a-*(ll*)b;
  return d>0?1:d<0?-1:0;
}
ll getk(ll k){
  ll h=k,l1=0,r1=k-1,l2=0,r2=k-1;
  while(h>0){
    ll m1=(l1+r1)/2,m2=(l1+r2)/2;
    if(a[m1]>b[m1]){
      r1=m1; l2=m2;
    }else{
      l1=m1;r2=m2;
    }
    h/=2;
  }
  if(a[r1]>b[r2]) return b[r2]; else return a[r1];
}
int main(){
  scanf("%lld%lld%lld",&m,&n,&k);
  ll i,j;
  for(i=0;i<m;++i) scanf("%lld",a+i);
  for(i=0;i<n;++i) scanf("%lld",b+i);
  qsort(a,m,sizeof(ll),cmp);
  qsort(b,n,sizeof(ll),cmp);
  for(i=0;i<k;++i){
    printf("%lld\n",getk(i));
  }
  return 0;
}
