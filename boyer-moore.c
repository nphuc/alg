#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 1000100
long n,m;
char a[maxN],b[maxN];
long os[300];
long lcs[maxN];
long ms[maxN];
static inline getString(char *a,long *n){
    register long i=0;
    for(;;){
        a[i]=getchar_unlocked();
        if(isalpha(a[i])) break;
    }
    while(isalpha(a[i])){
        a[++i]=getchar_unlocked();
    }
    *n=i;
}
static inline void  occ_shift(char *p,long m){
    register long i;
    for(i='a';i<='z';++i){
        os[i]=-1;
    }
    for(i=0;i<m;++i){
        os[p[i]]=i;
    }
}   
#define min2(a,b) ((a)<(b)?(a):(b))
static inline void suffix(char *p,long m){
    register long i,l,r;
    for(i=0;i<m;++i){
        lcs[i]=0;
    }
    lcs[m-1]=m;
    l=r=m-1;
    for(i=m-2;i>=0;--i){
        if((l<i) && (lcs[i+m-1-r]<i-l)){
            lcs[i]=lcs[i+m-1-r];
        }else{
            l=min2(l,i);
            r=i;
            while((l>=0) && (p[l]==p[l+m-1-i]))--l;
            lcs[i]=r-l;
        }
    }
}
static inline void matching_shift(char *p,long m){
    register long i,k;
    for(i=0;i<m;++i){
        ms[i]=0;        
    }   
    i=0;
    for(k=1;k<=m;++k){
        if((k==m) || (lcs[m-1-k]==m-k)){
            while(i<k){
                ms[i]=k;
                ++i;
            }
        }
    }
    for(k=m-1;k>0;--k){
        ms[m-1-lcs[m-1-k]]=k;
    }
}
#define max2(a,b) ((a)>(b)?(a):(b))
#define printNumber(n) do{\
    char __p[21];\
    register char __plen=0;\
    register unsigned long long __n=(n);\
    while(__n||!__plen){ __p[__plen++]=__n%10; __n/=10;}\
    while(__plen--){putchar_unlocked('0'+__p[__plen]);}\
}while(0)
int main(){
    getString(a,&n);
    getString(b,&m);
    occ_shift(b,m);
    suffix(b,m);
    matching_shift(b,m);
    register long i,j=0;
    while(j<=n-m){
        i=m-1;
        while(i>=0 && b[i]==a[i+j]){
            i--;
        }
        if(i==-1){
            printNumber(j+1);
            putchar_unlocked(' ');
            i=0;
        }
        j = j + max2(ms[i],i-os[a[i+j]]);
    }
    return 0;
}
