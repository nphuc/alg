#include <stdio.h>
#include <stdlib.h>

#define M 1000000003
#define m3(x) ((((x*x)%M)*x)%M)
typedef long long ll;
int main(){
    ll *a,t,*f,*g;
    ll i,maxn=0;
    scanf("%lld",&t);
    a=malloc(sizeof(ll)*t);
    for(i=0;i<t;++i){
        scanf("%lld",a+i);
        if(a[i]>maxn) maxn=a[i];
    }
    f=malloc(sizeof(ll)*(maxn+2));
    g=malloc(sizeof(ll)*(maxn+2));
    f[0]=0;
    f[1]=1;
    g[1]=1;
    for(i=2;i<=maxn;++i){
        f[i]=(f[i-1]+m3(i))%M;
        g[i]=(g[i-1]+f[i])%M;
    }
    for(i=0;i<t;++i){
        printf("%lld\n",g[a[i]]);
    }
    free(a);free(f);free(g);
    return 0;
}
