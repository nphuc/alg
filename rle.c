#include <stdio.h>
#include <stdlib.h>

int main(){
    char c,st;
    long count;
    char s[20];
    for(;;){
        c=getchar_unlocked();
        while(!isalpha(c)){
            if(c==EOF) goto _end;
            c=getchar_unlocked();
        }
        count=0;
        st=c;
        while(isalpha(c)){
            if(st==c){
                ++count;
            }else{
                if(count>3){
                    sprintf(s,"%ld!%c",count,st);
                    printf("%s",s);
                }else{
                    long i=0;
                    for(i=0;i<count;++i) putchar_unlocked(st);
                }
                count=1;
                st=c;
            }
            c=getchar_unlocked();
            if(!isalpha(c)){
                if(count>3){
                    sprintf(s,"%ld!%c",count,st);
                    printf("%s",s);
                }else{
                    long i=0;
                    for(i=0;i<count;++i) putchar_unlocked(st);
                }
                putchar_unlocked('\n');
            }
        }
    }
_end:
    return 0;
}
