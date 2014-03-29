#include <stdio.h>
#include <stdlib.h>
 
typedef long long ll;
 
#define true 1
#define false 0
ll powmod(ll a,ll p,ll m){
    ll res=1,t=a;
    while(p!=0){
        if(p%2==1){
            res=(res*t)%m;
        }
        t=(t*t)%m;
        p>>=1;
    }
    return res;
}
int rb_a(ll n,ll a){
    if(n==2) return true ;
    if(n%2==0) return false;
    ll s=0,m=n-1;
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
int main(){
    ll i,t,in;
    scanf("%lld",&t);
    for(i=0;i<t;++i){
        scanf("%lld",&in);
        if(rb_a(in,2)||
                rb_a(in,3)&&
                rb_a(in,5)&&
                rb_a(in,7)&&
                rb_a(in,11)&&
                rb_a(in,13)&&
                rb_a(in,17)){
             
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
