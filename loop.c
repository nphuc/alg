#include <stdio.h>
int main(){
    long long a=1;
    long long c=0;
    for(;;){
        a=(a+1234567890)%2147483648;
        ++c;
        if(a==1) break;
    }
    printf("%lld\n",c);
    return 0;
}
