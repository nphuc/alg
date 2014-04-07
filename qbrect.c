#include <stdio.h>
#include <stdlib.h>

#define M 1010
#ifdef __cplusplus 
#define isdigit(c) ((c)>='0' &&(c<='9'))
#endif
int m,n;
int s[M][M];
int ind[M],height[M];
static inline int maxArea(int *hist,int n){
    register int i,max=0,size=0,t,lastid;
    for(i=0;i<n;++i){
        if(size==0 || hist[i]>height[size-1]){
            ind[size]=i;
            height[size]=hist[i];
            ++size;
        }else if(hist[i]<height[size-1]){
            lastid=0;
            while(size>0 &&hist[i]<height[size-1]){
                lastid=ind[size-1];
                t=height[size-1]*(i-lastid);
                if(t>max) max=t;
                --size;
            }
            ind[size]=lastid;
            height[size]=hist[i];
            ++size;
        }
    }
    while(size){
        t=height[size-1]*(n-ind[size-1]);
        --size;
        if(t>max) max=t;
    }
    return max;
}
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
    m=getInt(),n=getInt();
    register int j,i;
    register char c;
    int t,res=0;
    for(j=0;j<m;++j){
        for(i=0;i<n;++i){
            do{
                c=getchar_unlocked();
            }while(!isdigit(c));
            s[j][i]=c-'0';
            if(s[j][i] && j>0){
                s[j][i]=s[j-1][i]+1;
            }
        }
        t=maxArea(s[j],n);
        if(t>res) res=t;
    }
    printf("%d",res);
    return 0;
}
