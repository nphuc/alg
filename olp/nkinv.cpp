#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
using namespace std;
#define f_i "NKINV.INP"
#define f_o "NKINV.OUT"
FILE *fi,*fo;
#define maxN 60100
long n,a[maxN],m,
     c[maxN],
     ind[maxN];
void readfile(){
  fi=fopen(f_i,"r");
  //fi=stdin;
  fscanf(fi,"%ld",&n);
  long i;
  for(i=1;i<=n;++i) fscanf(fi,"%ld",&(a[i]));
  fclose(fi);
}
void init(){
  long i;
  for(i=1;i<=n;++i){
    c[i]=0;
  }
  c[0]=0;
  ind[0]=1;
  m=1;
  a[0]=LONG_MIN;
  a[n+1]=LONG_MAX;
}
long Find(long i){
  long median,j,st=1,nd=m+1;
  do{
    median=(st+nd)/2;
    j=ind[median];
    if(a[j]>a[i]) st=median;else nd=median;
  }while(st+1!=nd && st!=nd);
  return ind[st];
}
void solve(){
  long i,j,k;
  for(i=1;i<=n;++i){
    j=Find(i);
    k=c[j]+1;
    if(k>m){
      m=k;
      ind[k]=i;
    }else{
      if(a[ind[k]]<a[i]) ind[k]=i;
    }
    c[i]=k;
  }
}
int main(){
  readfile();
  init();
  long i;
  solve();
  long s=0;
  for(i=1;i<=n;++i) {
    s+=c[i];
    printf("%ld %ld %ld\n",i,ind[i],c[i]);
  }
  printf("s=%ld\n",s-n);
  printf("m=%ld\n",m);
}
