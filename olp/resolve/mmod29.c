#include <stdio.h>
#include <stdlib.h>

#define f_i "MMOD29.INP"
#define f_o "MMOD29.out"
#define MAX 10100100

typedef long long num;
int memo[MAX];
void create(){
  num i,t2,t3,t167,res,next2,next3,next167;
  next2=1;
  t2=1;
  next3=1;t3=1;next167=1;t167=1; /* 2004 =2^2 * 3 * 167 */
  memo[0]=1;
  for(i=1;i<=10000000;++i){
    next2=(next2*2)%29; /* 2 lan lap cho so 2 */
    t2=(t2+next2)%29;
    next2=(next2*2)%29;
    t2=(t2+next2)%29;
    next3=(next3*3)%29;
    t3=(t3+next3)%29;
    next167=(next167*167)%29;
    t167=(t167+next167)%29;
    memo[i]=(t2*t3*t167)%29;
  }
}
int main(){
  FILE *fi,*fo;
  //fi=fopen(f_i,"r");
  fi=stdin;
  //fo=fopen(f_o,"w");
  fo=stdout;
  int eof;
  num n,i;
  create();
  for(;;){
    eof=fscanf(fi,"%lld",&n);
    if(eof!=1 || n==0) break;
    fprintf(fo,"%i\n",memo[n]);
  }
  fclose(fi);fclose(fo);
  return 0;
}
