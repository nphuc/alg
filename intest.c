#include <stdio.h>
#include <stdlib.h>

#define ISDGIT(x) ((x)>='0' && (x)<='9')
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
    long x,res=0, n=getLong(),k=getLong();
    while(n--){
        x=getLong();
        if(x%k==0) ++res;
    }
    printf("%ld",res);
    return 0;
}
