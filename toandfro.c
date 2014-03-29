#include <stdio.h>
#include <stdlib.h>

static inline int getInt(){
    register int res=0;
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
static inline int getString(char*s){
    register int len=0;
    register char c;
    for(;;){
        c=getchar_unlocked();
        if(isalpha(c)) break;
    }
    while(isalpha(c)){
        s[len]=c;
        ++len;
        c=getchar_unlocked();
    }
    s[len]=0;
    return len;;
}
static inline void putString(char*s){
    register int i=0;
    while(s[i]){
        putchar_unlocked(s[i]);
        ++i;
    }
}
int main(){
    char s[300];
    register int n,i,j;
    while((n=getInt())){
        register int len=getString(s),m,x,y;
        m=len/n;
        for(x=0;x<n;++x){
            for(y=0;y<m;++y){
                if(y%2==0){
                    putchar_unlocked(s[y*n+x]);
                }else{
                    putchar_unlocked(s[(y+1)*n-x-1]);
                }
            }
        }
        putchar_unlocked('\n');
    };
    return 0;
}
