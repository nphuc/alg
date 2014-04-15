#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned long long ll;
typedef long double ld;
#define maxN 1010
ll x[maxN],y[maxN];
int f[maxN][maxN],m,n;
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
        rb_a(n,11);
        //rb_a(n,13)&&
        //rb_a(n,17);
}
ll root2(ll n){
    ll t=(ll)powl((ld)n,1./2);
    if(t*t==n) return t;
    ++t;
    if(t*t==n) return t;
    return 0;
}

ll root3(ll n){
    ll t=(ll)powl((ld)n,1./3);
    if(t*t*t==n) return t;
    ++t;
    if(t*t*t==n) return t;
    return 0;
}
void read(ll *a,int *n){
    register int c;
    register ll t;
    register int i=0;
    for(;;){
        t=0;
        for(;;){
            c=getchar_unlocked();
            if(c=='\n'||c==EOF) goto _end;
            if(isdigit(c)) break;
        }
        while(isdigit(c)){
            t=t*10+c-'0';
            c=getchar_unlocked();
        }
        a[i++]=t;
        if(c=='\n'||c==EOF) break;
    }
_end:
    *n=i;
}
#define max2(a,b) ((a)>(b)?(a):(b))
int ok(ll n){
    if(n==1) return true;
    ll r2=root2(n);
    if(r2) return true;
    ll r3=root3(n);
    if(r3 && isprime(r3)) return true;
    return false;
}

int main(){
    read(x,&n);
    read(y,&m);
    register int i,j;
    //for(i=0;i<n;++i) printf("%4llu",x[i]);printf("\n");
    //for(i=0;i<m;++i) printf("%4llu",y[i]);printf("\n");
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            if(x[i]==y[j] && ok(x[i])){
                if(i==0||j==0){
                    f[i][j]=1;
                }
                else f[i][j]=f[i-1][j-1]+1;
            }else{
                if(i==0||j==0) f[i][j]=f[0][0];
                else f[i][j]=max2(f[i-1][j],f[i][j-1]);
            }
            //printf("%3d",f[i][j]);
        }
        //printf("\n");
    }
    printf("%d",f[n-1][m-1]);
    return 0;
}
