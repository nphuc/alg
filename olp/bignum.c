#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i "BIGNUM.INP"
#define f_o ""
typedef long long ll;
#define B 100000000
#define max 1010
#define maxN 300
typedef struct num{
  ll a[maxN];
  int n;
  int d; /*dau*/
}num;
num reverse(const num *a){
  num res;
  int i;
  res.d=a->d;
  res.n=a->n;
  for(i=0;i<a->n;++i) res.a[i]=a->a[a->n-1-i];
  return res;
}
void rm0(num *res){
  while(res->n>1 && res->a[res->n-1]==0) --res->n;
}
void p(const num *a){
  int i;
  if(a->d==1 &&a->a[0]!=0) printf("-");
#if B==100000000
#define C 8
  printf("%lld",a->a[0]);
  for(i=1;i<a->n;++i) printf("%08lld",a->a[i]);
#else
#define C 1
  for(i=0;i<a->n;++i) printf("%d",a->a[i]);
#endif
  printf("\n");
}
num add_(const num *a,const num *b){
  num res;
  int i=a->n-1,j=b->n-1;
  res.d=0;
  res.n=0;
  ll sodu=0;
  while(i>=0 && j>=0){
    sodu=sodu+a->a[i]+b->a[j];
    res.a[res.n]=sodu%B;
    sodu/=B;
    ++res.n;
    --i;--j;
  }
  while(i>=0){
    sodu=sodu+a->a[i];
    res.a[res.n]=sodu%B;
    sodu/=B;
    ++res.n;
    --i;
  }
  while(j>=0){
    sodu=sodu+b->a[j];
    res.a[res.n]=sodu%B;
    sodu/=B;
    ++res.n;
    --j;
  }
  while(sodu!=0){
    res.a[res.n]=sodu%B;
    sodu/=B;
    ++res.n;
  }
  rm0(&res);
  return reverse(&res);
}
num sub_(const num *a,const num *b){/*a>=b*/
  ll t,memo=0;
  ll i=a->n-1,j=b->n-1;
  num res;
  res.n=0;
  res.d=0;
  while(j>=0){
    t=memo+a->a[i]-b->a[j];
    if(t<0){
      memo=-1;
      res.a[res.n]=t+B;		
    }else{
      memo=0;
      res.a[res.n]=t;
    }
    ++res.n;
    --i;--j;
  }
  while(i>=0){
    t=memo+a->a[i];
    if(t<0){
      memo=-1;
      res.a[res.n]=t+B;		
    }else{
      memo=0;
      res.a[res.n]=t;
    }
    ++res.n;
    --i;
  }
  rm0(&res);
  return reverse(&res);
}
int cmp(const num *a,const num *b){ /* so sanh tri tuyet doi*/
  if(a->n!=b->n) return a->n-b->n;
  int i;
  for(i=a->n-1;i>=0;--i){
    if(a->a[i]!=b->a[i]) return a->a[i]-b->a[i];
  }
  return 0;
}
num add(const num *a,const num *b){
  num res;
  if(a->d==0 && b->d==0){
    res= add_(a,b);
  }else if(a->d==1 &&b->d==1 ){
    res=add_(a,b);
    res.d=1;
  }else if(a->d==1 &&b->d==0){
    if(cmp(a,b)>=0){
      res=sub_(a,b);
      res.d=1;
    }else{
      res=sub_(b,a);
      res.d=0;
    }
  }else {
    if(cmp(a,b)>=0){
      res=sub_(a,b);
      res.d=0;
    }else{
      res=sub_(b,a);
      res.d=1;
    }
  }
  return res;
}
num mul1_(const num *a,ll d){ /*nhan 2 so duong*/
  num res;
  res.d=0;
  res.n=0;
  ll sodu=0;
  int i;
  for(i=a->n-1;i>=0;--i){
    sodu=sodu+a->a[i]*d;
    res.a[res.n]=sodu%B;
    sodu/=B;
    ++res.n;
  }
  while(sodu!=0){
    res.a[res.n]=sodu%B;
    sodu/=B;
    ++res.n;
  }
  rm0(&res);
  res=reverse(&res);
  return res;
}
num copy(const num *a){
  num res;
  res.n=a->n;
  res.d=a->d;
  int i;
  for(i=0;i<res.n;++i){
    res.a[i]=a->a[i];
  }
  return res;
}
num mul(const num *a,const num *b){
  num res,t,x;
  res.n=0;
  int i;
  for(i=0;i<b->n;++i){
    res.a[res.n]=0;
    ++res.n;
    t=mul1_(a,b->a[i]);
    x=add_(&res,&t);
    res=x;
  }
  if( a->d==b->d){
    res.d=0;
  }else{
    res.d=1;
  }
  res=reverse(&res);
  rm0(&res);
  res=reverse(&res);
  return res;
}
ll ctoll(char *s,long st,long nd){
  long i;
  ll n=0;
  for(i=st;i<nd;++i){
    n=n*10+*(s+i)-'0';
  }
  return n;
}
num cton(char *s){
  long len=strlen(s);
  long i=len;
  num res;
  char *t=s;
  res.n=0;
  while(i>C){
    res.a[res.n]=ctoll(s,i-C,i);
    i-=C;
    ++res.n;
  }
  if(i==0) {
  }else{
    res.a[res.n]=ctoll(s,0,i);
    ++res.n;
  }
  rm0(&res);
  return reverse(&res);
}
num a,b,ad,sb,ml;
char s1[max],s2[max];
int main(){

  //FILE *fi=fopen(f_i,"r");
  FILE*fi=stdin;
  fscanf(fi,"%s%s",s1,s2);
  if(s1[0]=='-'){
    a=cton(s1+1);
    a.d=1;
  }else{
    a=cton(s1);
    a.d=0;
  }
  if(s2[0]=='-'){
    b=cton(s2+1);
    b.d=1;
  }else{
    b=cton(s2);
    b.d=0;
  }
  ad=add(&a,&b);
  ml=mul(&a,&b);
  b.d=1-b.d;
  sb=add(&a,&b);
  p(&ad);p(&sb); p(&ml);
  //num t=mul1_(&a,98989898);p(&t);
  //printf("%d",ml.n);
  /*
     p(&a);printf("\n");
     p(&b);printf("\n");
  */
  return 0;
}
