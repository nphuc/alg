#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
int cmp(const void *a,const void *b){
  ll x=*(ll*)a,y=*(ll*)b;
  return x>y?1:x<y?-1:0;
}
void solve(){
  int n;
  int i;
  scanf("%d",&n);
  ll sum,sumjk;
  ll *a=malloc(sizeof(ll)*n+1);
  for(i=0;i<n;++i){
    scanf("%lld",a+i);
  }
  qsort(a,n,sizeof(ll),cmp);
  int j,k;
  scanf("%lld",&sum);
  for(i=0;i<n-2;++i){
    sumjk=sum-a[i];
    j=i+1;
    k=n-1;
    while((j<k) && (j<n) &&( k>i)) {
      if(a[j]+a[k]==sumjk) {
        printf("YES\n");
        return;
      }else{
        if(a[j]+a[k]>sumjk) --k;
        else ++j;
      }
    }
  }
  printf("NO\n");
  free(a);
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--)solve();
  return 0;
}
