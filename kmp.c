#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 1000100
long n,m;
char a[maxN],b[maxN];
long map[maxN]; 
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
static inline compute_kmp(char *p,long m){
    register long i,j;
    for(i=0;i<=m;++i){
        map[i]=-1;
    }
    i=1;map[i]=0;j=map[i];
    while(i<m){
        if(p[i]==p[j]){
            map[i]=map[j];
        }else{
            map[i]=j;
            while(j>=0 &&p[i]!=p[j]){
                j=map[j];
            }
        }
        i++;
        j++;
    }
    map[m]=j;
}
int main(){
    getString(a,&n);
    getString(b,&m);
    compute_kmp(b,m);
    register long i,j;
    i=0;
    for(j=0;j<n;++j){
        while(i>=0 &&a[j]!=b[i]){
            i=map[i];
        }
        i++;
        if(i==m){
            printf("%ld ",j-m+2);
            i=map[i];
        }   
    }
    return 0;
}
