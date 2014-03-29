#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxN 1010
long memo[maxN];
long issquare(long n){
    long x=(long)sqrt(n);
    if(x*x==n) return x;
    else return 0;
}
long get(long n){
    if(memo[n]) return memo[n];
    long t=issquare(n);
    if(t){
        memo[n]=1;
    }else{
        long i=n-1;
        long res=10000;
        while(i>=n/2){
            long a=get(i)+get(n-i);
            if(a<res) res=a;
            --i;
        }
        memo[n]=res;
    }
    return memo[n];
}
int main(){
    long t,n;
    memset(memo,0,sizeof(long)*maxN);
    memo[0]=1;
    memo[1]=1;
    scanf("%ld",&t);
    while(t--){
        scanf("%ld",&n);
        printf("%ld\n",get(n));
    }
    return 0;
}
