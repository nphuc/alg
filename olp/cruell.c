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
#define maxN 2000
typedef struct num{
  ll a[maxN];
  int n;
}num;
num reverse(const num *a){
  num res;
  int i;
  res.n=a->n;
  for(i=0;i<a->n;++i) res.a[i]=a->a[a->n-1-i];
  return res;
}
void rm0(num *res){
  while(res->n>1 && res->a[res->n-1]==0) --res->n;
}
void p(const num *a){
  int i;
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
num mul1_(const num *a,ll d){ /*nhan 2 so duong*/
  num res;
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
num res,t;
void output(){
  char s[12];
  sprintf(s,"%lld",res.a[0]);
  long t,i=strlen(s);
  printf("%s",s);
  int j;
  for(t=1;t<res.n;++t){
    sprintf(s,"%08lld",res.a[t]);
    for(j=0;j<C;++j){
      if(i%70==0) printf("\n");
      printf("%c",s[j]);
      ++i;
    }
  }
}
int main(){
  ll n,m;
  scanf("%lld%lld",&n,&m);
  if(n>=B){
    t.a[0]=n%B;
    t.a[1]=(n/B)%B;
    t.n=2;
  }else{
    t.a[0]=n;
    t.n=1;
  }
  res.n=1;
  res.a[0]=1;
  while(m!=0){
    if(m%2==1){
      res=mul(&res,&t);
    }
    t=mul(&t,&t);
    m/=2;
  }
  output();
  return 0;
}
