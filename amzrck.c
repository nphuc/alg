#include <stdio.h>
#include <stdlib.h>

long memo[2000]={1,2,3},n=2;

long getLong(){
    long res=0;
    char c;
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
long get(long i){
    if(i<=n) return memo[i];
    while(n<=i){
        ++n;
        memo[n]=memo[n-1]+memo[n-2];
    }
    return memo[i];
}
int main(){
    long t=getLong();
    while(t--){
        long x=getLong();
        printf("%ld\n",get(x));
    }
    return 0;
}
