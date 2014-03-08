#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int cmp(const void *a,const void *b){
  long d=*(long*)a-*(long*)b;
  return d>0?1:d<0?-1:0;
}
#define maxN 100100
#define abs(x) ((x)>0?(x):-(x))
#ifndef LLONG_MAX
#define LLONG_MAX ((long)(1<<(sizeof(long)-1)-1))
#endif
long n,b[maxN],c[maxN];
int main(){
  scanf("%ld",&n);
  long i;
  for(i=0;i<n;++i) scanf("%ld",b+i);
  for(i=0;i<n;++i) scanf("%ld",c+i);
  qsort(b,n,sizeof(long),cmp);
  qsort(c,n,sizeof(long),cmp);
  long mb,mc,stb=0,stc=0,ndb=n-1,ndc=n-1;

  long res=LLONG_MAX;
  while(stb<ndb || stc<ndc){
    mb=(stb+ndb)/2;
    mc=(stc+ndc)/2;
    /*
     *  b-> , <-c
     */
    long t=b[mb]+c[mc];
    if(t>0){
      ndb=mb-1;
    }else{
      stc=mc+1;
    }
    if(abs(t)<res) res=abs(t);
  }
  printf("%ld",res);
  return 0;
}
