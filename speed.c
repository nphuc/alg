#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x)>0?x:-(x))
#define min2(a,b) ((a)<(b)?(a):(b))
#define max2(a,b) ((a)>(b)?(a):(b))
float solve(float a,float b){
    if(a*b<=0){
        return ABS(a-b);
    }
    a=ABS(a);
    b=ABS(b);
    int x=min2(a,b),y=max2(a,b);
    // t*x+x=yt
    return (float)x/(y-x);
}
int main(){
    int t;
    float a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%f%f",&a,&b);
        printf("%f\n",solve(a,b));
    }
    return 0;
}
