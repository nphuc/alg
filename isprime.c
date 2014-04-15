#define true 1
#define false 0
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
}
ll powmod(ll a,ll p,ll m){
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
int isprime(ll n){
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
