#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num{
    char s[250];
    int l;
}num;

void read(num *n){
    register int i,c;
    while(!isdigit(c=getchar_unlocked())){
        c=getchar_unlocked();
        if(c==EOF) exit(0);
    }
    i=0;
    while(isdigit(c)){
        n->s[i]=c-'0';
        ++i;
        c=getchar_unlocked();
    }
    if(c==EOF) exit(0);
    n->l=i;
}
int mod2(num *n){
    return n->s[n->l-1]%2==0;
}
int mod5(num *n){
    return n->s[n->l-1]%5==0;
}
long sumdigit(num *n){
    long r=0;
    int i;
    for(i=0;i<n->l;++i) r+=n->s[i];
    return r;
}
int mod4(num *n){
    if(n->l>=2){
        return (n->s[n->l-2]*10+n->s[n->l-1])%4==0;
    }else{
        return n->s[n->l-1]%4==0;
    }
}
int mod8(num *n){
    if(n->l>=3){
        return (n->s[n->l-3]*100+n->s[n->l-2]*10+n->s[n->l-1])%8==0;
    }else if(n->l==2){
        return (n->s[n->l-2]*10+n->s[n->l-1])%8==0;
    }else{
        return n->s[n->l-1]%8==0;
    }
}
int mod7(num *n){
    int sodu=0;
    int bm=1;
    int i;
    for(i=n->l-1;i>=0;--i){
        sodu=(sodu+bm*n->s[i])%7;
        bm=(bm*10)%7;
    }
    return sodu==0;
}
int solve(num *n){
    long s=sumdigit(n);
    int i,r=0;
    int memo[]={
        0,
        1,
        mod2(n),
        s%3==0,
        mod4(n),
        mod5(n),
        mod2(n)&&(s%3==0),
        mod7(n),
        mod8(n),
        s%9==0};

    for(i=0;i<n->l;++i){
        r+=memo[n->s[i]];
    }
    return r;
}
int main(){
    num n;
    int i;
    while(1){
        read(&n);
        printf("%d\n",solve(&n));
    }
    return 0;
}
