#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
typedef unsigned long long ll;
#define true 1
#define false 0
#define mul_mod(a,b,m) ((a)*(b)%(m))
static inline ll powmod(ll a,ll p,ll m){
    ll res=1,t=a;
    while(p!=0){
        if(p%2){
            res=mul_mod(res,t,m);
        }
        t=mul_mod(t,t,m);
        p>>=1;
    }
    return res;
}
static inline int rb_a(ll n,ll a){
    register ll s=0,m=n-1;
    while(m%2==0){
        ++s;
        m>>=1;
    }
    register ll b=powmod(a,m,n);
    if(b==1) return true;
    int i;
    for(i=0;i<s;++i){
        if((b+1)%n==0)return true;
        b=mul_mod(b,b,n);
    }
    return false;
}
static inline int isprime(ll n){
    if(n==2||n==7||n==61) return true;
    if(!rb_a(n,2))return false;
    if(!rb_a(n,7))return false;
    if(!rb_a(n,61))return false;
    return true;
}
static inline ll solve(ll n){
    register ll t;
    if(n==3) return 2;
    if(n%2){
        t=n-2;
    }else{
        t=n-1;
    }
    while(!isprime(t)) t-=2;
    return t;
}
static inline ll getLL(){
    ll res=0;
    register char c;
    for(;;){
        c=getchar_unlocked();
        if(isdigit(c)) break;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res;
}
#define printNumber(n) do{\
        char __p[21];\
        register char __plen=0;\
        register unsigned long long __n=(n);\
        while(__n){ __p[__plen++]=__n%10; __n/=10;}\
        while(__plen--){putchar_unlocked('0'+__p[__plen]);}\
    }while(0)
int main(){
    register int t=(int)getLL();
    while(t--){
        printNumber(solve(getLL()));
        putchar_unlocked('\n');
    }
    return 0;
}
