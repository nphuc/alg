#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    long i;
    printf("%ld\n",500000);
    for(i=0;i<500000;++i){
        printf("%ld ",rand()%1000000000);
    }
    return 0;
}
