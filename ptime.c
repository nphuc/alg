#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef long ll;
 
#define true 1
#define false 0
static inline ll powmod(ll a,ll p,ll m){
    register  ll res=1,t=a;
    while(p!=0){
        if(p%2==1){
            res=(res*t)%m;
        }
        t=(t*t)%m;
        p>>=1;
    }
    return res;
}
static inline int rb_a(ll n,ll a){
    if(n==2||n==3) return true ;
    if(n%2==0||n==1) return false;
    register ll s=0,m=n-1;
    while(m%2==0){
        ++s;
        m>>=1;
    }
    ll b=powmod(a,m,n);
    if(b-1==0) return true;
    int i;
    for(i=0;i<s;++i){
        if((b+1)%n==0)return true;
        b=(b*b)%n;
    }
    return false;
}
static inline int isprime(ll in){
     if(rb_a(in,2)&&
                rb_a(in,3)
                ){
         return 1;
     }else return 0;
}
int res[10010];
int main(){
    int n;
    scanf("%d",&n);
    memset(res,0,sizeof(int)*(n+2));
    register int i,t,k,l=2;
    for(i=2;i<=n;++i){
        k=i;
        t=2;
        while(t*t<=k && k!=1){
            if(isprime(t) && (k%t==0)){
                k=k/t;
                res[t]++;
                if(t>l)l=t;
            }else{
                t++;
            }
        }
        if(k!=1){
            res[k]++;
            if(k>l)l=k;
        }

    }
    for(i=2;i<=n;++i){
        if(res[i]==0)continue;
        if(i==l){
            printf("%d^%d",i,res[i]);
        }else{
            printf("%d^%d * ",i,res[i]);
        }
    }
    return 0;
}
