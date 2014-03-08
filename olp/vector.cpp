#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>

using namespace std;

#define f_i "VECTOR.INP"
#define f_o "VECTOR.OUT"
typedef struct vt{
  long x,y;
  vt(){}
  vt(long x,long y):x(x),y(y){}
  vt operator+(const vt &o)const {
    return vt(x+o.x,y+o.y);
  }
  vt operator=(const vt &o){
    x=o.x;
    y=o.y;
    return *this;
  }
  bool operator<(const vt&o) const{
    if(x<o.x) return x<o.x;
    return y<o.y;
  }
  bool operator==(const vt&o) const{
    return (x==o.x&& y==o.y);
  }
}vt;

FILE *fi;
long n;
typedef vector<vt> array;
typedef array::iterator AI;

array a;
vt u;
void readfile(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  fscanf(fi,"%ld",&n);
  long i;
  vt t;
  for(i=0;i<n;++i){
    fscanf(fi,"%ld%ld",&(t.x),&(t.y));
    a.push_back(t);
  }
  fscanf(fi,"%ld%ld",&(u.x),&(u.y));
  fclose(fi);
}
long res;
long x[40];

int main(){
  readfile();
  long i,j,k;
  res=0;
  vt sum;
  for(k=1;k<=n;++k){
    for(i=0;i<k;++i) x[i]=i;
    for(;;){
      sum=vt(0,0);
      for(i=0;i<k;++i){
        sum=sum+a[x[i]];
      }
      if(sum==u)++res;
      i=k-1;
      while(i>=0 &&x[i]==n+i-k)--i;
      if(i<0) break;
      ++x[i];
      for(j=i+1;j<k;++j) x[j]=x[j-1]+1;
    }
  }
  printf("%ld",res);
}
