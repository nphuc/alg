#include <stdio.h>
#include <stdlib.h>
 
typedef long long ll;
 
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
    if(n==2) return true ;
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
                //rb_a(in,3)&&
                //rb_a(in,5)&&
                rb_a(in,7)&&
               // rb_a(in,11)&&
                //rb_a(in,13)&&
                rb_a(in,61)
                //rb_a(in,17
                ){
         return 1;
     }else return 0;
}
ll a=1;
int main(){
    register long t=10;
    while(t--){
        if(isprime(a)){
            putchar_unlocked('1');
        }else{
            putchar_unlocked('0');
        }
        a=(a+1234567890)%2147483648;
    }
    return 0;
}
