#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxN 60100
#define f_i "NKINV.INP"
long a[maxN],n;
FILE *fi;
int cmp(const void *a ,const void *b){
  long d=*(long*)a-*(long*)b;
  return d>0?1:d<0?-1:0;
}
int main(){ 
  fi=fopen(f_i,"r");
  fscanf(fi,"%ld",&n);
  long i,res;
  for(i=0;i<n;++i){
    fscanf(fi,"%ld",a+i);
  }
  printf("%ld",res);
  return 0;
}
