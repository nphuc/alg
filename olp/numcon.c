#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "NUMCON.INP"
#define f_o ""
typedef long long ll;
typedef struct num{
  char s[110];
}num;

num n[100];
char nlen;
int cmp(const void *a,const void *b){
  num n1=*(num*)a;
  num n2=*(num*)b;
  char i=0,l1=strlen(n1.s),l2=strlen(n2.s);
  for(;;){
    if(i>=l1) return -1;
    if(i>=l2) return 1;
    if(n1.s[i]!=n2.s[i]) return n2.s[i]-n1.s[i];
    ++i;
  }
  return 0;
}
int main(){
  nlen=0;
  //FILE *fi=fopen(f_i,"r");
  FILE *fi=stdin;
  while(fscanf(fi,"%s",n[nlen].s)!=-1){
    ++nlen;
  }
  fclose(fi);
  qsort(n,nlen,sizeof(num),cmp);
  char i;
  for(i=0;i<nlen;++i){
    printf("%s",n[i].s);
  }
  return 0;
}
