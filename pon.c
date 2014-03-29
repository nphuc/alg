#include <stdio.h>
#include <stdlib.h>
 
typedef long long ll;
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
static inline int getInt(){
    int res=0;
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
#define true 1
#define false 0
static inline ll mul_mod(ll a, ll b, ll m)
{
    long double x;
    ll c;
    ll r;
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    x = a;
    c = x * b / m;
    r = (ll)(a * b - c * m) % (ll)m;
    return r < 0 ? r + m : r;
}
static inline ll pow_mod(ll a,ll p,ll m){
    ll res=1,t=a;
    while(p){
        if(p%2){
            res=mul_mod(res,t,m);
        }
        p>>=1;
        t=mul_mod(t,t,m);
    }
    return res;
}
static inline int rb_a(ll n,ll a){
    if(n%2==0) return false;
    ll s=0,m=n-1;
    while(m%2==0){
        ++s;
        m>>=1;
    }
    ll b=pow_mod(a,m,n);
    if(b-1==0) return true;
    register int i;
    for(i=0;i<s;++i){
        if((b+1)%n==0) return true;
        b=mul_mod(b,b,n);
    }
    return false;
}
int prime1(ll n){
    if(n==2||n==3||n==5||n==7||n==11||n==13||n==17) return true;
    return 
        rb_a(n,2)&&
        rb_a(n,3)&&
        rb_a(n,5)&&
        rb_a(n,7)&&
        rb_a(n,11)&&
        rb_a(n,13)&&
        rb_a(n,17);
}
#include <time.h>
int isprime(ll n){
    int i=0,r=1;
    if(n<341550071728321LL) return prime1(n);
    for(i=0;i<6;++i){
        ll a=rand()%(n-3)+2;
        r=r&&rb_a(n,a);
    }
    return r;
}
int main(){
    ll n;
    register int i=getInt();
    srand(time(NULL));
    while(i--){
        n=getLL();
        printf("%s\n",isprime(n)?"YES":"NO");
    }
    return 0;
}
