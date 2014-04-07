#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
typedef long long ll;
#define true 1
#define false 0
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll mul_mod(ll a, ll b, ll m)
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
    /*
    __int128_t ml=(a*b);
    return (ll) (ml%m);
    */
}
ll powmod(ll a,ll p,ll m){
    ll res=1,t=a;
    while(p!=0){
        if(p%2==1){
            res=mul_mod(res,t,m);
        }
        t=mul_mod(t,t,m);
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
        b=mul_mod(b,b,n);
    }
    return false;
}
int isprime(ll a){
    if(a==2||a==7||a==61) return 1;
    return rb_a(a,2)&&rb_a(a,7)&&rb_a(a,61);
}
#include <time.h>
#define Abs(x) ((x)>0?(x):-(x))
ll pollard(ll n){
    if(n%2==0) return 2;
    ll x,y,c,d;
_next:
    x=rand()%(1000000000)+2;
    c=rand()%(1000000000)+2;
    y=x;
    d=1;
    while(d==1){
        x=(mul_mod(x,x,n)+c)%n;
        y=(mul_mod(y,y,n)+c)%n;
        y=(mul_mod(y,y,n)+c)%n;
        d=gcd(Abs(x-y),n);
    }
    if(isprime(d)|| d>=INT_MAX) return d;
    else{
        n=d;
        goto _next;
    }
}

int main(){
    srand(time(NULL));
    ll n;
    scanf("%lld",&n);
    if(n<=1){
        printf("0");
        return 0;
    }
    ll r=pollard(n);
    if(r>INT_MAX){
        printf("0");
    }else{
        ll i=0;
        while(n%r==0){
            n/=r;
            ++i;
        }
        if(n==1 && i>1){
            printf("%lld %lld",r,i);
        }else{
            printf("0");
        }
    }
    return 0;
}   
