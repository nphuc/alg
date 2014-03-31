#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef struct num{
    char s[200];
    int l;
}num;
#define B 3
static inline long getLong(){
    register long res=0;
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
static inline void rm0(num *n){
    register int i=0;
    int first=1;
    while(n->s[i]==0){
        ++i;
    }
    memmove(n->s,n->s+i,n->l-i);
    n->l-=i;
}
static inline void read(num *n){
    register int c;
    register int i=0;
    do{
        c=getchar_unlocked();
        if(c==EOF) exit(0);
    }while(!isdigit(c));
    while(isdigit(c)){
        n->s[i]=c-'0';
        ++i;
        c=getchar_unlocked();
    }
    if(c==EOF) exit(0);
    n->l=i;
}
static inline void mul5(num *n,num *res){
    register int j=0,i=n->l-1;
    register long sodu=0;
    while(i>=0){
        sodu=n->s[i]*5+sodu;
        res->s[j]=sodu%B;
        --i;
        ++j;
        sodu/=B;
    }
    while(sodu){
        res->s[j]=sodu%B;
        sodu/=B;
        ++j;
    }
    register char tmp;
    for(i=0;i<j/2;++i){
        tmp=res->s[i];
        res->s[i]=res->s[j-1-i];
        res->s[j-1-i]=tmp;
    }
    res->l=j;
}
static inline void output(num *n){
    register int i=0;
    for(i=0;i<n->l;++i){
        printf("%d",n->s[i]);
    }
}
static inline int div2(num *a,num *res){
    register int i,j;
    int memo=0,v;
    for(i=0;i<a->l;++i){
        v=memo*3+a->s[i];
        res->s[i]=v/2;
        memo=v%2;
    }
    res->l=a->l;
    rm0(res);
    return memo;
}

long powmod(long a,num *n,long m){
    ll res=1,t=a;
    num tmp=*n;
    while(tmp.l>0){
        if(div2(&tmp,&tmp)){
            res=(res*t)%m;
        }
        t=(t*t)%m;
    }
    return (long) res;
}
int main(){
    num b;
    long a,t,m;
    t=getLong();
    while(t--){
        a=getLong();
        read(&b);
        m=getLong();
        printf("%ld\n",powmod(a,&b,m));
    }
    return 0;
}
