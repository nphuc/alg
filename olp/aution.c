#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i ""
#define f_o ""
typedef long long ll;
#define max 1002
#define min2(a,b) ((a)<(b)?(a):(b))
long a[max],m,n;
int cmp(const void *a,const void *b){
  long d=*(long*)a-*(long*)b;
  return d>0?1:d<0?-1:0;
}
int main(){
  scanf("%ld%ld",&n,&m);
  long i,len,price;
  ll res=0,t;
  for(i=0;i<m;++i) scanf("%ld",a+i);
  qsort(a,m,sizeof(long),cmp);
  for(i=0;i<m-1;++i){
    t=a[i]*min2(m-i,n);
    if(t>res){
      price=a[i];
      res=t;
    }
  }
  printf("%ld %lld",price,res);
  return 0;
}
