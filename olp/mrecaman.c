#include <stdio.h>
#include <stdlib.h>

#define maxN 500100
typedef long long ll;
ll a[maxN]={0,1},n=1;
int cmp(const void *a,const void *b){
  ll d=*(ll*)a-*(ll*)b;
  return d>0?1:d<0?-1:0;
}
ll get(ll i){
  if(i<=n) return a[n];
  for(++n;n<=i;++n){
    ll m=a[n-1]-n;
    if(m>0){
      ll *t=(ll*)lsearch(&m,a,n+1,sizeof(ll),cmp);
      if(t==NULL){
        a[n]=m;
      }else{
        a[n]=a[n-1]+n;
      }
    }else{
      a[n]=a[n-1]+n;
    }
  }
  return a[n];
}

int main(){
  printf("%lld\n",get(2));
}
