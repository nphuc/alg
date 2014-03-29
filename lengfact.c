#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lg10 2.302585092994046
typedef long long ll;
ll length(ll n){
    if(n==0||n==1) return 1;
    double t1=0.5*logl(2*M_PI*n);
    double t2=n*logl(n/M_E);
    return (ll)((t1+t2)/lg10+1);
}
int main(){
    int t;
    ll n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",length(n));
    }
    return 0;
}
