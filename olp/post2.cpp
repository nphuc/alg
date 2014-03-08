#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i "POST2.INP"
#define f_o ""
FILE *fi,*fo;
#define max 100100
long n,a[max],b[max],c[max];
void readfile(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  fscanf(fi,"%ld",&n);
  long i;
  for(i=0;i<n;++i) fscanf(fi,"%ld",a+i);
  for(i=0;i<n;++i) fscanf(fi,"%ld",b+i);
  for(i=0;i<n;++i) fscanf(fi,"%ld",c+i);
  fclose(fi);
}
long solve(long sta,long nda,long stb,long ndb,long sum){
  long ma,mb;
  if(sta>nda|| stb>ndb) return 0;
  ma=(sta+nda)/2;
  mb=(stb+ndb)/2;
  long res=0;
  if(a[ma]+b[mb]==sum){
    ++res;
    res+=solve(sta,ma-1,stb,ndb,sum);
    res+=solve(ma+1,nda,stb,ndb,sum);
  }else{
    if(a[ma]+b[mb]<sum){
      res+=solve(ma+1,nda,stb,mb-1,sum);
      res+=solve(ma+1,nda,mb+1,ndb,sum);
      res+=solve(sta,ma-1,mb+1,ndb,sum);
    }else{
      res+=solve(sta,ma-1,stb,mb-1,sum);
      res+=solve(sta,ma-1,mb+1,ndb,sum);
      res+=solve(ma+1,nda,stb,mb-1,sum);
    }
  }
  return res;
}
int main(){
  readfile();
  sort(a,a+n-1);
  sort(b,b+n-1);
  long i,res=0;
  for(i=0;i<n;++i){
    res+=solve(0,n-1,0,n-1,c[i]);
  }
  printf("%ld\n",res);
}
