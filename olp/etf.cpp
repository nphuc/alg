#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define f_i ""
#define f_o ""

typedef map<long,long> uoc;
typedef uoc::iterator UI;
typedef vector<long> array;
typedef array::iterator AI;
long p[200],plen;
void create(){
  p[0]=2;
  p[1]=3;
  plen=2;
  long i,t=p[plen-1];
  while(t<=1000){
    ++t;
    for(i=0;p[i]<=sqrtl(t);++i){
      if(t%p[i]==0) goto _next;
    }
    p[plen]=t;
    ++plen;
_next:;
  }
}
uoc ts(long n){
  uoc res;
  long i=0;
  for(;;){
    if(n%p[i]==0) {
      ++(res[p[i]]);
      n=n/p[i];
    }else{
      ++i;
    }
    if(i>=plen){
      res[n]=1;
      break;
    }
    if(n==1) break; 
  }
  return res;
}
long su(long n){
  UI ui;
  uoc r=ts(n);
  long res=1;
  for(ui=r.begin();ui!=r.end();++ui){
    res*=(ui->second)+1;
    printf("%ld %ld\n",ui->first,ui->second);
  }
  return res-1;
}
long solve(long n){
  UI ui;
  if(n==1) return 0;
  uoc r=ts(n);
  long res=0;
  array a;
  for(ui=r.begin();ui!=r.end();++ui){
    a.push_back(ui->first);
  }
  long k,s=a.size();
  long *x=new long[s],i,j,tich,trung=0;
  for(i=0;i<s;++i){
    res+=n/a[i]-1;
  }
  for(k=2;k<=s;++k){
    for(i=0;i<k;++i){
      *(x+i)=i;
    }
    for(;;){
      tich=1;
      for(i=0;i<k;++i){
        tich*=a[x[i]];
      }
      trung+=n/tich-1;
      i=k-1;
      while(i>=0 && *(x+i)==s+i-k)--i;
      if(i<0) break;
      ++*(x+i);
      for(j=i+1;j<k;++j) *(x+j)=*(x+j-1)+1;
    }
  }
  delete []x;
  return res-trung+1;
}
int main(){
  create();
  long a[20000];
  long t;
  long i;
  scanf("%ld",&t);
  for(i=0;i<t;++i) scanf("%ld",a+i);
  for(i=0;i<t;++i){
    printf("%ld\n",a[i]-solve(a[i]));
  }
}
