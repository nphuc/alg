#include <stdio.h>
#include <stdlib.h>

#define N 5005
long a[N],n;
long b[N];
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

int main(){
    n=getLong();
    register long i,j;
    for(i=0;i<n;++i){
        a[i]=getLong();
        b[i]=0;
    }
    long res=0;
    for(j=0;j<n;++j){
_continue:
        for(i=0;i<n;++i){
            if(i+j<n){
                b[i]+=a[i+j];
                if(i>0 && b[i]==b[i-1]){
                    res=j;
                    goto _continue;          
                }
            }
        }
    }
    printf("%ld",res);
    return 0;
}
