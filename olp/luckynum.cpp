#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i ""
#define f_o ""

int mod(int p,int m){
  int res=1,i;
  for(i=0;i<p;++i){
    res=(res*10)%m;
  }
  return res;
}
int summod(int p,int m){
  int res=1;
  int t=1,i;
  for(i=0;i<p;++i){
    t=(t*10)%m;
    res=(res+t)%m;
  }
  return res;
}
typedef struct res{
  int r6,r8,t;
}res;
int n,a[300];
res solve(int m){
  int s,i,t1,t2;
  res rt;
  for(s=1;s<=200;++s){
    for(i=0;i<s;++i){
      if(i==0){
        t1=(summod(s,m)*6)%m;
        t2=(summod(s,m)*8)%m;
      }else{
        t1=(6*summod(i,m)*mod(s-i,m)+summod(s-i,m)*8)%m;
        t2=(8*summod(i,m)*mod(s-i,m)+summod(s-i,m)*6)%m;
      }
      if(t1==0){
        rt.r6=i;rt.r8=s-i;rt.t=1;
        return rt;
      }
      if(t2==0){
        rt.r8=i;rt.r6=s-i;rt.t=2;
        return rt;
      }
    }
  }
  rt.t=0;
  return rt;
}
int main(){
  int i,k;
  res r;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",a+i);
  for(i=0;i<n;++i){
    r=solve(a[i]);
    if(r.t==0){
      printf("-1\n");
    }else if(r.t==1){
      for(k=0;k<r.r6;++k) printf("6");
      for(k=0;k<r.r8;++k) printf("8");
      printf("\n");
    }else if(r.t==2){
      for(k=0;k<r.r8;++k) printf("8");
      for(k=0;k<r.r6;++k) printf("6");
      printf("\n");
    }
  }
}
