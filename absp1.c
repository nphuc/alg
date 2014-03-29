#include <stdio.h>
#include <stdlib.h>

typedef long long ll;


ll a[10010],n;
int cmp(const void *a,const void *b){
    ll d=*(ll*)a-*(ll*)b;
    return d>0?1:d<0?-1:0;
}
static inline void solve(){
    scanf("%lld",&n);
    register ll i=n;
    while(i--){
        scanf("%lld",a+n-1-i);
    }
    qsort(a,n,sizeof(ll),cmp);
    register ll res=0,s=0;
    for(i=1;i<n;++i){
        s+=a[i-1];
        res+=i*a[i]-s;
    }
    printf("%lld\n",res);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
