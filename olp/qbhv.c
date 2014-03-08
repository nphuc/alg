#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "QBHV.INP"
#define f_o ""
typedef long long ll;
#define max 15
char s[max];
int n;
void readfile(){
  //FILE *fi=fopen(f_i,"r");
  scanf("%s",s);
  n=strlen(s);
}
int cmp(const void *a,const void *b){
  return *(char*)a-*(char*)b;
}
int c[max],clen;
void init(){
  qsort(s,n,sizeof(char),cmp);
  clen=0;
  char *prev=s;
  int i;
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
}
void swap(char *a,char *b){
  char t=*a;
  *a=*b;
  *b=t;
}
long gt(long n){
  long r=1,i;
  for(i=1;i<=n;++i) r*=i;
  return r;
}
int main(){
  readfile();
  init();
  int i,j,k,a,b;
  long len=gt(n);
  for(i=0;i<clen;++i){
    len/=gt(c[i]);
  }
  printf("%ld\n",len);
  for(;;){
    for(j=0;j<n;++j){
      printf("%c",s[j]);
    }
    printf("\n");
    i=n-2;
    while(i>=0 &&s[i]>=s[i+1])--i;
    if(i<0) break;
    k=n-1;
    while(s[k]<=s[i]) --k;
    swap(s+k,s+i);
    a=i+1;b=n-1;
    while(a<b) {
      swap(a+s,b+s);
      ++a;
      --b;
    }
  }
  return 0;
}
