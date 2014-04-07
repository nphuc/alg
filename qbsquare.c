#include <stdio.h>
#include <stdlib.h>

#define M 1010
int s[M][M],r1[M][M],r0[M][M];

#define min2(a,b) ((a)<(b)?(a):(b))
#define min3(a,b,c) min2(min2(a,b),c)
int getInt(){
    int res=0;
    char c;
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
int main(){
    int m=getInt(),n=getInt();
    int mx=0;
    register int i,j;
    char c;
    for(j=0;j<m;++j){
        for(i=0;i<n;++i){
            do{
                c=getchar_unlocked();
            }while(!isdigit(c)); 
            s[j][i]=c-'0';
        }
    }
    for(j=0;j<m;++j){
        r1[j][0]=s[j][0];
        r0[j][0]=1-s[j][0];
        if(r1[j][0]>mx) mx=r1[j][0];
        if(r0[j][0]>mx) mx=r0[j][0];
    }
    for(i=1;i<n;++i){
        r1[0][i]=s[0][i];
        r0[0][i]=1-s[0][i];
        if(r1[0][i]>mx) mx=r1[0][i];
        if(r0[0][i]>mx) mx=r0[0][i];
    }
    for(j=1;j<m;++j){
        for(i=1;i<n;++i){
            if(s[j][i]==0){
                r1[j][i]=0;
                r0[j][i]=min3(r0[j-1][i],r0[j][i-1],r0[j-1][i-1])+1;
            }else{
                r0[j][i]=0;
                r1[j][i]=min3(r1[j-1][i],r1[j][i-1],r1[j-1][i-1])+1;
            }
            if(r1[j][i]>mx) mx=r1[j][i];
            if(r0[j][i]>mx) mx=r0[j][i];
        }
    }
    printf("%d",mx);
    return 0;
}
