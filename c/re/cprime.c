#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
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
/*

   if n < 1,373,653, it is enough to test a = 2 and 3;
   if n < 9,080,191, it is enough to test a = 31 and 73;
   if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
   if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
   if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
   if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
   if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
   */
int isprime(ll n){
    if(n==2||n==7||n==61) return true;
    return rb_a(n,2)&&rb_a(n,7)&&rb_a(n,61);
}
ll test[1010],test_len=0,maxtest=0;
ll prevr,clen=0,plen=0;
int main(){
    ll i,in;
    /*while(scanf("%lld",test+test_len)!=EOF && test[test_len] !=0){
        if(test[test_len]>maxtest) maxtest=test[test_len];
        ++test_len;
    }*/
    prevr=-1;
    for(i=2;i<=100000000;++i){
        if(isprime(i)){
            ++plen;
        }
        ll r=(ll) ((((float)plen-i*log(M_E)/log(i))/plen)*1000);
        if(r!=prevr){
            printf("%lld %lld %lld\n",r,i,plen);
        }else{
            prevr=r;
        }
    }
    return 0;
}
