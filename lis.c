#include <stdio.h>
#include <stdlib.h>
typedef long ll;
#define maxN 30100
static inline long getLong(){
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
ll a[maxN],m,n,l[maxN],startOf[maxN];
static inline void init(){
    a[0]=-99999999;
    a[n+1]=99999999;
    m=1;
    l[n+1]=1;
    startOf[1]=n+1;
}
static inline ll find(ll i){
    register ll inf,sup,median,j;
    inf=1;sup=m+1;
    do{
        median=(inf+sup)/2;
        j=startOf[median];
        if(a[j]>a[i]) inf=median;else sup=median;
    }while(inf+1!=sup);
    return startOf[inf];
}
static inline void solve(){
    register ll i,j,k;
    for(i=n;i>=0;--i){
        j=find(i);
        k=l[j]+1;
        if(k>m){
            m=k;
            startOf[k]=i;
        }else{
            if(a[startOf[k]]<a[i]) startOf[k]=i;
        }
        l[i]=k;
    }
}
int main(){
    register ll i;   
    n=getLong();
    for(i=1;i<=n;++i)a[i]=getLong();
    init();
    solve();
    printf("%ld",m-2);
    return 0;
}
