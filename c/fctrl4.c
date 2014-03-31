#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct num{
    char s[105];
    int l;
}num;
static inline int getInt(){
    register int res=0;
    register char c;
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
static inline void read(num *n){
    register int c;
    register int i=0;
    do{
        c=getchar_unlocked();
        if(c==EOF) exit(0);
    }while(!isdigit(c));
    while(isdigit(c)){
        n->s[i]=c-'0';
        ++i;
        c=getchar_unlocked();
    }
    if(c==EOF) exit(0);
    n->l=i;
}
static inline void mul2(num *n,num *res){
    register int j=0,i=n->l-1;
    register long sodu=0;
    while(i>=0){
        sodu=n->s[i]*2+sodu;
        res->s[j]=sodu%10;
        --i;
        ++j;
        sodu/=10;
    }
    while(sodu){
        res->s[j]=sodu%10;
        sodu/=10;
        ++j;
    }
    register char tmp;
    for(i=0;i<j/2;++i){
        tmp=res->s[i];
        res->s[i]=res->s[j-1-i];
        res->s[j-1-i]=tmp;
    }
    res->l=j;
}
static inline void output(num *n){
    register int i=0;
    for(i=0;i<n->l;++i){
        printf("%d",n->s[i]);
    }
}
static inline void add1(num *n){
    register int i=n->l-1;
    while(n->s[i]==9){
        i--;
        n->s[i]=0;
    }
    if(i<0){
        memmove(n->s+1,n->s,n->l);
        n->s[0]=1;
        n->l++;
    }else{
        n->s[i]++;
    }
}
static inline void div5(num *n,num *res){
    if(n->l==1){
        res->l=1;
        res->s[0]=n->s[0]/5;
    }else{
        n->l--;
        mul2(n,res);
        n->l++;
        if(n->s[n->l-1]>=5){
            add1(res);
        }
    }
}
static int last[]={1,1,2,6,4,2,2,4,2,8};
static inline int nonzero(num *n){
    if(n->l==1){
        return last[n->s[0]];
    }
    num res;
    div5(n,&res);
    int r=last[n->s[n->l-1]%5];
    register int mod4;
    if(res.l>1)mod4=(res.s[res.l-2]*10+res.s[res.l-1])%4;
    else mod4=res.s[res.l-1]%4;
    int pow2=6;
    while(mod4){
        pow2=(pow2*2)%10;
        mod4--;
    }
    return (r*pow2*nonzero(&res))%10;
}
int main(){
    num n;
    for(;;){
        read(&n);
        printf("%d\n",nonzero(&n));
    }
    return 0;
}
