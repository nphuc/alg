#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
#define maxK 10100
ll f[maxK]={0,1,2},k,n,s;
int cmp(const void *a,const void *b){
  ll d=*(ll*)a-*(ll*)b;
  return d>0?1:d<0?-1:0;
}
int main(){
  scanf("%lld%lld%lld",&n,&s,&k);
  ll i;
  for(i=3;i<=n;++i){
    f[i]=(f[i-1]+f[i-2])%k;
  }
  qsort(f+1,n,sizeof(ll),cmp);
  for(i=1;i<=n;++i)printf("%lld\n",f[i]);
  return 0;
}
