#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define f_i "CRUELL.INP"

#define maxN 2000
#define last (maxN-1)
#define B 100000000
typedef unsigned long long ll;
typedef struct num {
  ll a[maxN];
  int h;
}num;
ll m[maxN][maxN];
void rm0(num *n){
  while(n->a[n->h]==0 && n->h<last) ++n->h;
}
void output(const num *n){
  char s[20];
  long c;
  int j,i=n->h;
  sprintf(s,"%llu",n->a[i]);
  c=strlen(s);
  printf("%s",s);
  ++i;
  for(;i<=last;++i){
    sprintf(s,"%08llu",n->a[i]);
    for(j=0;j<8;++j){
      if(c%70==0){
        printf("\n");
      }
      printf("%c",s[j]);
      ++c;
    }
  }
}
num mul(const num *a,const num *b){
  int i,j; /*i>j*/
  for(i=0;i<maxN-a->h;++i){
    for(j=0;j<maxN-b->h;++j){
      m[i][j]=a->a[last-i]*b->a[last-j];
    }
  }
  num res;
  ll sodu=0;
  int s,x,y,t,l=last;
  for(s=0;s<i+j;++s){
    for(t=0;t<=s;++t){
      if(t>=i|| s-t>=j) continue;
      sodu+=m[t][s-t];
    }
    res.a[l]=sodu%B;
    sodu/=B;
    --l;
  }
  while(sodu!=0){
    res.a[l]=sodu%B;
    sodu/=B;
    --l;
  }
  res.h=l+1;
  rm0(&res);
  return res;
}
int main(){
  num res,t;
  ll n,p;
  scanf("%llu%llu",&n,&p);
  if(n>B){
    t.a[last]=n%B;
    t.a[last-1]=(n/B)%B;
    t.h=last-1;
  }else{
    t.a[last]=n;
    t.h=last;
  }
  res.a[last]=1;
  res.h=last;
  while(p!=0){
    if(p%2!=0){
      res=mul(&t,&res);
    }
    t=mul(&t,&t);
    p/=2;
  } 
  output(&res);
  printf("\n");
  return 0;
}
