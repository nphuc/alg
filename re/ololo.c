#include <stdio.h>
long getLong(){
    long res=0;
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
int main(){
    long n,r=0;
    register long i;
    scanf("%ld",&n);
    i=n;
    while(i--){
        scanf("%ld",&n);
        r^=n;
    }
    printf("%ld",r);
    return 0;
}
