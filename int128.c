#include <stdio.h>
#include <inttypes.h>
#include <limits.h>
void print128(__int128_t i){
    printf("%llu",(long long)(i/LLONG_MAX));
    printf("%llu",(long long)(i%LLONG_MAX));

}
int main(){
    __int128_t a=((__int128_t)123456789123456)*((__int128_t)123456789123456);
    print128(a);
    return 0;
}
