#include <stdio.h>

typedef long long ll;
int main(){
    ll n;
    scanf("%lld",&n);
    while(n>1){
        if(n%2==0) n=n/2;
        else n=n*3+3;
        if(n==3) break;
    }
    printf("%s",n==1?"TAK":"NIE");
    return 0;
}
