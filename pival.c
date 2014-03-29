    #include <stdio.h>
    long long a=1000000000,b=0,c=52514,d,e,f[52514],g;
    int main(){
    int fi=1;
    for(;b-c;)f[b++]=a/5;
    for(;d=0,g=c*2;c-=14,(!fi?printf("%.9lld",e+d/a):
    (fi=!fi,printf("%1.8f",(float)(e+d/a)/a*10))),
    e=d%a)
    for(b=c;d+=f[b]*a,f[b]=d%--g,d/=g--,--b;d*=b);
    return 0;
    }
