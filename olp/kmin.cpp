#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i "KMIN.INP"
#define f_o ""
FILE *fi,*fo;
#define max 102000
long m,n,k,
     a[max],b[max],c[max],
     ia[max],ib[max];
void AP(long *a,long n){
  long i;
  for(i=0;i<n;++i){
    printf("%-4ld",*(a+i));
  }
  printf("\n");
}
int main(){
  fi=fopen(f_i,"r");
  fscanf(fi,"%ld%ld%ld",&m,&n,&k);
  long i;
  for(i=0;i<m;++i) fscanf(fi,"%ld",a+i);
  for(i=0;i<n;++i) fscanf(fi,"%ld",b+i);
}
