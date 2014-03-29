#include <stdio.h>
#include <stdlib.h>

#define ISDGIT(x) ((x)>='0' && (x)<='9')
long long getLong(){
    long long res=0;
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
int main(){
    long long t,i=0,n;
    t=getLong();
    while(t--){
        n=getLong();
        printf("Case %lld: %.2f\n",++i,4*n*n+0.25);
    }
    return 0;
} 
