#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i ""
#define f_o ""
typedef long long ll;
#define maxN 10100
char s[maxN];
long n;
void readfile(){
  //FILE *fi=fopen(f_i,"r");
  scanf("%s",s);
}
int cmp(const void *a,const void *b){
  return *(char*)a-*(char*)b;
}
long c[256],clen;
void init(){
/*  qsort(s,n,sizeof(char),cmp);
  clen=0;
  char *prev=s;
  long i;
  for(i=0;i<n;++i){
    if(cmp(prev,s+i)){
      c[clen]=s+i-prev;
      prev=s+i;
      ++clen;
    }
  }
  if(cmp(s+n-1,prev)){
    c[clen]=s+n-1-prev;
    ++clen;
  }else{
    c[clen]=s+n-1-prev+1;
    ++clen;
  }
  */
  long i;
  for(i='a';i<='z';++i) c[i]=0;
  n=0;
  while(s[n]){
    ++c[s[n]];
    ++n;
  }
}
void swap(char *a,char *b){
  char t=*a;
  *a=*b;
  *b=t;
}
long f5[maxN],f2[maxN];
typedef struct cnt{
  long c2,c5;
}cnt;
#define min2(a,b) ((a)<(b)?(a):(b))
cnt count(long n){
  static long prev=0;
  cnt r;
  if(n>prev){
    long t,c;
    for(prev=prev+1;prev<=n;++prev){
      t=prev;
      c=0;
      while(t%5==0){
        t/=5;
        ++c;
      }
      f5[prev]=f5[prev-1]+c;
      t=prev;
      c=0;
      while(t%2==0){
        t/=2;
        ++c;
      }
      f2[prev]=f2[prev-1]+c;
    }
  }
  r.c2=f2[n];r.c5=f5[n];
  return r;
}
int main(){
  readfile();
  init();
  f2[0]=0;
  f5[0]=0;
  cnt res,t;
  res=count(n);
  long i;
  for(i='a';i<='z';++i){
    t=count(c[i]);
    res.c2-=t.c2;
    res.c5-=t.c5;
  }
  printf("%ld",min2(res.c2,res.c5));
  return 0;
}
