#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "QBMAX.INP"
#define f_o ""

#define max 100
#define min (-1000000)
long a[max+2][max],m,n,s[max][max];
void readfile(){
  long i,j;
  FILE *fi=fopen(f_i,"r");
  //FILE *fi=stdin;
  fscanf(fi,"%ld%ld",&m,&n);
  for(j=1;j<=m;++j){
    for(i=0;i<n;++i){
      fscanf(fi,"%ld",&(a[j][i]));
    }
  }
  for(i=0;i<n;++i){
    a[0][i]=min;
    a[m+1][i]=min;
  }
  fclose(fi);
}
#define max2(a,b) ((a)>(b)?(a):(b))
#define max3(a,b,c) max2(max2(a,b),c)
void sum(){
  long i,j;
  for(j=0;j<=m+1;++j){
    s[j][0]=a[j][0];
  }
  for(i=1;i<n;++i){
    for(j=1;j<=m;++j){
      s[j][i]=a[j][i]+max3(s[j-1][i-1],s[j][i-1],s[j+1][i-1]);
    }
  }
}
int main(){
  readfile();
  sum();
  long j,mx=min;
  for(j=1;j<=m;++j){
    if(s[j][n-1]>mx) mx=s[j][n-1];
  }
  printf("%ld",mx);
  return 0;
}
