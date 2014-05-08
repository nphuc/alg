#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a)<(b)?a:b)
int main(){
    int n;
    scanf("%d",&n);
    char seq[n];
    int l[2*n+5];
    register int i=0,j,d,e,s,palLen,lLen,seqLen=n;
    register int c;
    do{
    	c=getchar_unlocked();
    }while(!isalpha(c));
    while(isalpha(c)){
    	seq[i++]=c;
    	c=getchar_unlocked();
    }
    
    i=0;
    palLen=0;
    lLen=0;
    while(i<seqLen){
        if(i>palLen && seq[i-palLen-1]==seq[i]){
            palLen+=2;
            i++;
            continue;
        }
        l[lLen++]=palLen;
        s=lLen-2;
        e=s-palLen;
        for(j=s;j>e;--j){
            d=j-e-1;
            if(l[j]==d){
                palLen=d;
                goto _break;
            }
            l[lLen++]=min(d,l[j]);
        }
        palLen=1;
        i++;
_break:;
    }
    l[lLen++]=palLen;
    s=lLen-2;
    e=s-(2*seqLen+1-lLen);
    for(i=s;i>e;--i){
        d=i-e-1;
        l[lLen++]=min(d,l[i]);
    }
    register res=0;
    for(i=0;i<lLen;++i){
        if(l[i]>res) res=l[i];
    }
    printf("%d",res);
    return 0;
}   
