#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define maxN 35
#define last (maxN-1)
#define B 100000000
#define C 8
typedef unsigned long long ll;typedef struct num{ ll a[maxN]; int h;}num;ll m[maxN][maxN];void rm0(num*n){ while(n->a[n->h]==0&&n->h<last)++n->h;}void output(const num*n){ long c; int i=n->h; printf("%lld",n->a[i]); for(++i;i<maxN;++i){ printf("%09lld",n->a[i]);}}ll ctoll(char *s,long st, long nd){long i;ll n=0;for(i=st;i<nd;++i){n=n*10+s[i]-'0';}return n;}num cton(char*s){ int len=strlen(s); long i=len; num res; char*t=s; res.h=last; while(i>C){ res.a[res.h]=ctoll(s,i-C,i); i-=C; --res.h;} if(i!=0){ res.a[res.h]=ctoll(s,0,i);} return res;}ll mod(num*a,ll m){ int i=last; ll basemod=1; ll res=0; while(i>=a->h){ res=(res+a->a[i]*basemod)%m; basemod=(basemod*B)%m; --i;} return res;}ll gcd(ll a,ll b){ ll tmp=a%b; while(tmp!=0){ a=b; b=tmp; tmp=a%b;} return b;}int main(){ int t,i,n; char s[500]; num a,res; scanf("%d",&t); while(t--){ scanf("%d%s",&n,s); a=cton(s); ll x=mod(&a,n); printf("%lld\n",gcd(x,n));} return 0;}