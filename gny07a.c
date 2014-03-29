#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[2000];
    int t,i,n,j,k;
    scanf("%d",&t);
    for(k=1;k<=t;++k){
        scanf("%i%s",&i,s);
        j=0;
        printf("%d ",k);
        while(s[j]){
            if(j+1==i) {++j;continue;}
            putchar_unlocked(s[j]);
            ++j;
        }
        putchar_unlocked('\n');
    }
    return 0;
}
