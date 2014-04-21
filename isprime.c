#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
typedef unsigned long long ll;
#define true 1
#define false 0

#define min2(a,b) ((a)<(b)?(a):(b))
#define max2(a,b) ((a)>(b)?(a):(b))

inline ll mul_mod(ll a, ll b, ll m)
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
inline ll pow_mod(ll a,ll p,ll m){
    ll res=1,t=a;
    while(p){
        if(p%2){
            res=mul_mod(res,t,m);
        }
        t=mul_mod(t,t,m);
        p>>=1;
    }
    return res;
}
inline int miller_rabin(ll n,ll a){
if(n==2) return true ;
    if(n%2==0) return false;
    ll s=0,m=n-1;
    while(m%2==0){
        ++s;
        m>>=1;
    }
    ll b=pow_mod(a,m,n);
    if(b-1==0) return true;
    int i;
    for(i=0;i<s;++i){
        if((b+1)%n==0)return true;
        b=mul_mod(b,b,n);
    }
    return false;
}
/*
 * f n < 1,373,653, it is enough to test a = 2 and 3;
 * if n < 9,080,191, it is enough to test a = 31 and 73;
 * if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
 * if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
 * if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
 * if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
 * if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
 */
inline int isprime(ll n){
    if(n==2||n==3||n==5||n==7||n==11||n==13) return true;
    return 
        miller_rabin(n,2)&&
        miller_rabin(n,3)&&
        miller_rabin(n,5)&&
        miller_rabin(n,7)&&
        miller_rabin(n,13)&&
        miller_rabin(n,17)&&
        miller_rabin(n,11);
}
int main(){
    printf("%d\n",isprime(300000007));
    return 0;
}
