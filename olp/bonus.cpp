#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
#define f_i "BONUS.INP"
#define f_o ""
FILE *fi,*fo;

#define max 1010

int m[max][max],n,k,l;
long long sum[max][max],res[max][max];
void readfile(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  fscanf(fi,"%d%d",&n,&k);
  int i,j;
  for(j=0;j<n;++j){
    for(i=0;i<n;++i){
      fscanf(fi,"%d",&(m[j][i]));
    }
  }
  fclose(fi);
  l=n-k+1;
}
void sumline(){
  int i,j;
  for(j=0;j<n;++j){
    sum[j][0]=0;
    for(i=0;i<k;++i){
      sum[j][0]+=m[j][i];
    }
    for(i=1;i+k<=n;++i){
      sum[j][i]=sum[j][i-1]+m[j][i+k-1]-m[j][i-1];
    }
  }
}
void sumrow(){
  int i,j;
  for(i=0;i<l;++i){
    res[0][i]=0;
    for(j=0;j<k;++j){
      res[0][i]+=sum[j][i];
    }
    for(j=1;j+k<=n;++j){
      res[j][i]=res[j-1][i]+sum[j+k-1][i]-sum[j-1][i];
    }
  }
}
int main(){
  readfile();
  sumline();
  sumrow();
  long long mx=-10000000000000;
  int i,j;
  for(j=0;j<l;++j){
    for(i=0;i<l;++i){
      if(res[j][i]>mx) mx=res[j][i];
    }
  }
  printf("%lld",mx);
}
