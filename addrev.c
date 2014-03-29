#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char i8;
typedef int i16;
typedef long i32;
typedef long long i64;

#define B 10
#define M 32014
#define last(n) ((n).hig-1)
typedef struct num {
  i8 n[M];
  i16 neg;
  i16 hig;
}num;
void print(num *n){
  i16 i;
  i8 first=1;
  for(i=0;i<n->hig;++i){
    if(!first || n->n[i]!=0){
      if(first) first=!first;
      printf("%d",(int) n->n[i]);
    }
  }
  printf("\n");
}
num reverse(num *n){
  num res;
  res.neg=n->neg;
  res.hig=0;
  i16 i;
  i8 first=1;
  for(i=last(*n);i>=0;--i){
    if(n->n[i]!=0 || !first) {
      if(first) first=!first;
      res.n[res.hig]=n->n[i];
      ++res.hig;
    }
  }
  return res;
}
num add_(num *a,num *b){
  num res;
  i16 ia=last(*a),
      ib=last(*b);
  res.hig=0;
  i64 sodu=0;
  while(ia >=0&& ib>=0){
    sodu+=(i64)(a->n[ia]+b->n[ib]);
    res.n[res.hig]=sodu%B;
    sodu/=B;
    ++res.hig;
    --ia;--ib;
  }
  while(ia>=0){
    sodu+=a->n[ia];
    res.n[res.hig]=sodu%B;
    sodu/=B;
    ++res.hig;
    --ia;
  }
  while(ib>=0){
    sodu+=b->n[ib];
    res.n[res.hig]=sodu%B;
    sodu/=B;
    ++res.hig;
    --ib;
  }
  while(sodu!=0){
    res.n[res.hig]=sodu%B;
    sodu/=B;
    ++res.hig;
  }
  return res;
}
num sub_(num *a,num *b){  /* a>=b*/
  num res;
  i64 t,memo=0;
  i16 ia=last(*a),
      ib=last(*b);
  res.hig=0;
  while(ib>=0){
    t=memo+a->n[ia]-b->n[ib];
    if(t<0){
      memo=-1;
      res.n[res.hig]=t+B;
    }else{
      memo=0;
      res.n[res.hig]=t;
    }
    ++res.hig;
    --ia;--ib;
  }
  while(ia>=0){
    t=memo+a->n[ia];
    if(t<0){
      memo=-1;
      res.n[res.hig]=t+B;
    }else{
      memo=0;
      res.n[res.hig]=t;
    }
    ++res.hig;
    --ia;
  }
  return res;
}
int cmp(num *a,num *b){
  i16 ia=last(*a),
      ib=last(*b);
  if(ia!=ib) return ia>ib?1:-1;
  i16 i;
  for(i=0;i<=ia;++i){
    if(a->n[i]!=b->n[i]) return a->n[i]>b->n[i]?1:-1;
  }
  return 0;
}

num readnum(){
  char s[M];
  num res;
  scanf("%s",s);
  i16 len=strlen(s);
  i16 i=0;
  if(s[0]=='-') {
    res.neg=1;
    ++i;
  }else res.neg=0;
  res.hig=len-res.neg;
  while(i<len){
    res.n[i-res.neg]=s[i]-'0';
    ++i;
  }
  return res;
}
num addrev(num *a,num *b){
  num x=reverse(a),
      y=reverse(b);
  num res=add_(&x,&y);
  return res;
}

int main(){
  int t,i;
  scanf("%d",&t);
  for(i=0;i<t;++i){
    num a=readnum();
    num b=readnum();
    num res=addrev(&a,&b);
    print(&res);
  }
  return 0;
}
