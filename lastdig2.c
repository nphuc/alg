#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
static int loop[]={1,1,4,4,2,1,1,4,4,2};
static int last[]={0,1,6,1,6,5,6,1,6,1};
static inline int lastdig(int a,ll b){
    int b10=a%10;
    int lp=loop[b10];
    int lst=1,t;
    if(b<lp){
        t=b;
        while(t>0){
            lst=(lst*b10)%10;
            --t;
        }
        return lst;
    }else{
        t=b%lp;
        while(t>0){
            lst=(lst*b10)%10;
            --t;
        }
        return (lst*last[b10])%10;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    int a;
    ll b;
    while(t--){
        scanf("%d%lld",&a,&b);
        printf("%d\n",lastdig(a,b));
    }
    return 0;
}
