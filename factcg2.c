#include <stdio.h>
#include <stdlib.h>

FILE *fi;
static long p[700]={2,3},plen=2;
static max=10001000;
void genprime(){
    register long t=p[plen-1];
    register int i;
    while(t*t<=max){
        ++t;
        i=0;
        while(p[i]*p[i]<=t){
            if(t%p[i]==0) goto _next;
            ++i;
        }
        p[plen]=t;
        ++plen;
_next:;
    }
}
static inline void putLong(long n){
    if(n==0){
        putchar_unlocked('0');
        return;
    }
    char s[15];
    register int i=0;
    while(n){ s[i]=n%10+'0';++i;n/=10;}
    while(i--){
        putchar_unlocked(s[i]);
    }
}
static long res[50]={1},rlen;
void solve(long n){
    register int i=0;
    rlen=1;
    while(i<plen &&n!=1){
        if(n%p[i]==0){
            res[rlen]=p[i];
            ++rlen;
            n/=p[i];
        }else{
            ++i;
        }
    }
    if(i>=plen){
        res[rlen]=n;
        ++rlen;
    }
}
int main(){
    genprime();
    register int i,j;
    long n;
#ifdef Test
    fi=fopen("factcg2.inp","r");
#else
    fi=stdin;
#endif
    while(fscanf(fi,"%ld",&n)==1){
        //printf("%ld\n",n);
        solve(n);
        for(j=0;j<rlen-1;++j){
            //printf("%ldx",res[j]);
            putLong(res[j]);
            putchar_unlocked(' ');
            putchar_unlocked('x');
            putchar_unlocked(' ');
        }
        putLong(res[rlen-1]);
        putchar_unlocked('\n');
    }
    return 0;
}

