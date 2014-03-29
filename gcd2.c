#include<stdio.h>
#include<string.h>
#define B 100000000
#define C 8
typedef unsigned long long ll;
typedef struct num{
    ll a[40];
    int h;
}num;
ll m[40][40];
void rm0(num*n){
    while(n->a[n->h]==0&&n->h<39)++n->h;
}
void output(const num*n){
    long c;
    int i=n->h;
    printf("%lld",n->a[i]);
    for(++i;i<40;++i){
        printf("%08lld",n->a[i]);
    }
}
ll ctoll(char *s,long st, long nd){
long i;
ll n=0;
for(i=st;i<nd;++i){
n=n*10+s[i]-'0';
}
return n;
}
num cton(char*s){
    int len=strlen(s);
    long i=len;
    num res;
    char*t=s;
    res.h=39;
    while(i>C){
        res.a[res.h]=ctoll(s,i-C,i);
        i-=C;
        --res.h;
    }
    if(i!=0){
        res.a[res.h]=ctoll(s,0,i);
    }
    return res;
}
ll mod(num*a,ll m){
    int i=39;
    if(m==0)return 0;
    ll b=1,r=0;
    while(i>=a->h){
        r=(r+a->a[i]*b)%m;
        b=(b*B)%m;
        --i;
    }
    return r;
}
ll gcd(ll a,ll b){
    if(b==0)return a;else return gcd(b,a%b);
}
int main(){
    int t,i,n;
    char s[500];
    num a,res;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s);
        a=cton(s);
        if(n!=0){
            ll x=mod(&a,n);
            printf("%lld\n",gcd(x,n));
        }else{
            output(&a);
            putchar_unlocked('\n');
        }
    }
    return 0;
}
