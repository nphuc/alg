#include <stdio.h>
#include <stdlib.h>

#define ISDGIT(x) ((x)>='0' && (x)<='9')
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
static inline void putLong(long n){
    if(n==0){
        putchar_unlocked('0');
        return;
    }
    char s[12];
    register int i=0;
    while(n){ s[i]=n%10+'0';++i;n/=10;}
    while(i--){
        putchar_unlocked(s[i]);
    }
}
static inline long solve(long n){
    long res=0;
    while(n>0){
        res+=n/5;
        n/=5;
    }
    return res;
}
int main(){
    register long res,n,t=getLong();
    while(t--){
        n=getLong();
        res=0;
    	while(n>0){
        	res+=n/5;
        	n/=5;
    	}
        putLong(res);
        putchar_unlocked('\n');
    }
    return 0;
}
