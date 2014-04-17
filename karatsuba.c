#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 8
#define B 100000000
#define N 500
#define CMP(a,b) ((a)>(b)?1:(a)<(b)?-1:0)
#define PLUS 1
#define MINUS (-PLUS)
#define max2(a,b) ((a)>(b)?(a):(b))

typedef long long ll;
typedef struct num{
    ll a[N];
    int sbit;
    int n;
}num;


void s_to_n(char *s,int st,int nd,num *n){
    // st,nd vitri dau va cuoi cung
    //   123456789  ->st=1 ;nd=9
    n->sbit=PLUS;
    register int i;
    int c=nd-st+1,j;
    int r=c%C;
    ll t=0;
    if(r>0){
        for(i=0;i<r;++i){
            t=t*10+s[st+i]-'0';
        }
        n->n=1;
        n->a[0]=t;
    }else{
        n->n=0;
    }
    for(j=0;j<c/C;++j){
        t=0;
        for(i=0;i<C;++i){
            t=t*10+s[r+st+j*C+i]-'0';
        }
        n->a[n->n]=t;
        ++n->n;
    }
}


void printNum(const num*n){
    if(n->sbit<0) printf("-");
    printf("%lld",n->a[0]);
    int i;
    for(i=1;i<n->n;++i){
        printf("%08lld",n->a[i]);
    }
    printf("\n");
}

int cmp_(const num *a, const num *b){
    // so sanh tri tuyet doi
    if(a->n!=b->n) return CMP(a->n,b->n);
    register int i;
    for(i=0;i<a->n;++i){
        if(a->a[i]!=b->a[i]) return CMP(a->a[i],b->a[i]);
    }
    return 0;
}

int cmp(num *a,num *b){
    if(a->sbit*b->sbit<0) return CMP(a->sbit,b->sbit);
    return a->sbit*cmp_(a,b);
}

void shift_left(num *a,int d){
    int i;
    for(i=a->n;i<a->n+d;++i) a->a[i]=0;
    a->n+=d;
}
void shift_right(num *a,int d){
    int i;
    a->n=a->n-d;
    if(a->n<1){
        a->n=1;
        a->a[0]=0;
        return;
    }
    for(i=0;i<a->n;++i){
        a->a[i]=a->a[i+d];
    }
}
void rm0(num *a){
    int c=0;
    while(a->a[0]==0 && c<a->n) ++c;
    shift_right(a,c);
}
#define RM0(hover,k,c) do{\
    int __i;\
    while((k)>1 &&hover[k-1]==0)--(k);\
    for(__i=0;__i<k;++__i){   \
        (c)->a[__i]=hover[k-1-__i];   \
    }   \
    (c)->n=k;\
}while(0)

void ll_to_n(num *a,ll n){
    ll hover[N];
    register int k=0;
    if(n==0){
        a->n=1;
        a->a[0]=0;
        a->sbit=PLUS;
        return;
    }
    a->sbit=CMP(n,0);
    n=n*a->sbit;
    while(n){
        hover[k++]=n%B;
        n/=B;
    }
    RM0(hover,k,a);
}
void add_(const num *a,const num *b,num *c){
    ll hover[N];
    int i=a->n-1,j=b->n-1,k=0;
    ll sodu=0;
    while(i>=0 && j>=0){
        sodu=a->a[i]+b->a[j]+sodu;
        hover[k++]=sodu%B;
        sodu/=B;
        --i;--j;
    }
    while(i>=0){
        sodu=a->a[i]+sodu;
        hover[k++]=sodu%B;
        sodu/=B;
        --i;
    }
    while(j>=0){
        sodu=b->a[j]+sodu;
        hover[k++]=sodu%B;
        sodu/=B;
        --j;
    }
    while(sodu){
        hover[k++]=sodu%B;
        sodu/=B;
    }
    RM0(hover,k,c);
}


void sub_(const num *a,const num *b,num *c) {
    // gia su a>b
    ll hover[N];
    register int i=a->n-1,j=b->n-1,k=0;
    ll memo=0,t;
    while(j>=0){
        t=a->a[i]-b->a[j]+memo;
        if(t<0){
            memo=-1;
            hover[k++]=t+B;
        }else{
            memo=0;
            hover[k++]=t;
        }
        --i;--j;
    }
    while(i>=0){
        t=a->a[i]+memo;
        if(t<0){
            memo=-1;
            hover[k++]=t+B;
        }else{
            memo=0;
            hover[k++]=t;
        }
        --i;
    }
    RM0(hover,k,c);
}

void mul1_(const num *a,ll d,num *c){
    ll hover[N];
    ll sodu=0;
    register int i=a->n-1,k=0;
    while(i>=0){
        sodu+=a->a[i]*d;
        hover[k++]=sodu%B;
        sodu/=B;
        --i;
    }
    while(sodu){
        hover[k++]=sodu%B;
        sodu/=B;
    }
    RM0(hover,k,c);
}

static inline void mul_(num *a,num *b,num *c){
    register int i;
    num t;
    c->n=1;
    c->a[0]=0;
    for(i=0;i<b->n;++i){
        shift_left(c,1);
        mul1_(a,b->a[i],&t);
        add_(c,&t,c);
        rm0(c);
    }
}
static inline void div_(num *a,num *b,num *c){
    num row,tmp;
    ll_to_n(&row,0);
    ll_to_n(&row,0);
    register int i;
    for(i=0;i<a->n;++i){
                
    }
}

static inline add(num *a,num *b,num *c){
    if(a->sbit==b->sbit){
        add_(a,b,c);
        c->sbit=a->sbit;
    }else{
        int compare=cmp_(a,b);
        if(compare>0){
            sub_(a,b,c);
        }else{
            sub_(b,a,c);
        }
        c->sbit=compare*a->sbit;
    }
    rm0(c);
}

static inline sub(num *a,num *b,num *c){
    if(a->sbit*b->sbit<0){
        add_(a,b,c);
        c->sbit=a->sbit;
    }else{
        int compare=cmp_(a,b);
        if(compare>0){
            sub_(a,b,c);
        }else{
            sub_(b,a,c);
        }
        c->sbit=compare*a->sbit;
    }
    rm0(c);
}


static inline  mul(num*a,num *b,num *c){
    mul_(a,b,c);
    c->sbit=a->sbit*b->sbit;
    rm0(c);
}
static inline split_at(num *a,int vt,num*l,num *r){
    int i;
    for(i=0;i<vt;++i){
        l->a[i]=a->a[i];
    }
    l->n=vt;
    l->sbit=a->sbit;
    for(;i<a->n;++i){
        r->a[i-vt]=a->a[i];
    }
    r->n=a->n-vt;
    r->sbit=a->sbit;
}

static inline karatsuba(num *a,num *b,num *c){
    if(a->n <2 ||b->n<2) {
        mul(a,b,c);
        return;
    }
    int m=max2(a->n,b->n);
    int m2=m/2;
    num l1,h1,l2,h2;
    split_at(a,m2,&h1,&l1);
    split_at(b,m2,&h2,&l2);
    num z0,z1,z2,lh1,lh2;
    add(&l1,&h1,&lh1);
    add(&l2,&h2,&lh2);
    printNum(&lh1);
    karatsuba(&l1,&l2,&z0);
    karatsuba(&lh1,&lh2,&z1);
    karatsuba(&h1,&h2,&z2);
    num t,t2;
    add(&z0,&z2,&t);
    sub(&z1,&t,&t2);
    shift_left(&t2,m2);
    shift_left(&z2,2*m2);
    add(&z0,&z2,c);
    add(c,&t2,c);
}


int main(){
    num a,b;
    char s1[1010],s2[1010];
    scanf("%s%s",s1,s2);
    if(s1[0]=='-'){
        s_to_n(s1,1,strlen(s1)-1,&a);
        a.sbit=MINUS;
    }else{
        s_to_n(s1,0,strlen(s1)-1,&a);
        a.sbit=PLUS;
    }
    if(s2[0]=='-'){
        s_to_n(s2,1,strlen(s2)-1,&b);
        b.sbit=MINUS;
    }else{
        s_to_n(s2,0,strlen(s2)-1,&b);
        b.sbit=PLUS;
    }
    num ad,sb,ml;
    add(&a,&b,&ad);
    printNum(&ad);
    sub(&a,&b,&sb);
    printNum(&sb);
    karatsuba(&a,&b,&ml);
    printNum(&ml);
    return 0;
}
