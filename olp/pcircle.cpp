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
typedef long long ll;
typedef list<int> Path;
typedef Path::iterator PI;
typedef map<int,Path> Graph;
typedef Graph::iterator GI;
typedef list<Path> Paths;
typedef Paths::iterator PSI;

int n;
Graph g;
int isprime(int n){
  int i;
  for(i=2;i<=sqrtl(n);++i){
    if(n%i==0) return 0;
  }
  return 1;
}
void create(){
  int i,j;
  for(i=1;i<=2*n;++i){
    for(j=i+1;j<=2*n;++j){
      if(isprime(i+j)){
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
}
Paths all(int st,int nd,Path &p,int lv){
  Paths res,newps;
  Path p1=Path(p);
  if(st==nd){
    if(lv==2*n){
      p1.push_back(nd);
      res.push_back(p1);
    }
    return res;
  }
  if(g.find(st)==g.end()){
    return res;
  }
  Path gn=g[st];
  PSI psi;
  for(PI pi=gn.begin();pi!=gn.end();++pi){
    if(find(p.begin(),p.end(),*pi)==p.end()){
      p1=Path(p);
      p1.push_back(st);
      newps=all(*pi,nd,p1,lv+1);
      for(psi=newps.begin();psi!=newps.end();++psi){
          res.push_back(*psi);
      }
    }
  }
  return res;
}
void PP(Path &p){
  PI pi;
  for(pi=p.begin();pi!=p.end();++pi){
    printf("%4d",*pi);
  }
  printf("\n");
}
void PSP(Paths&ps){
  PSI psi;
  for(psi=ps.begin();psi!=ps.end();++psi){
    PP(*psi);
  }
}
void GP(){
  PI pi;
  GI gi;
  for(gi=g.begin();gi!=g.end();++gi){
    printf("from %4d:",gi->first);
    PP(gi->second);
  }
}
int main(){
  n=8;
  create();
  //GP();
  Paths res;
  Path p;
  unsigned long c=0;
  for(int i=2;i<=2*n;++i){
    if(i%2==0){
      res=all(1,i,p,1);
      c+=res.size();
      PSP(res);
    }
  }
  printf("%lu",c);
  
}
