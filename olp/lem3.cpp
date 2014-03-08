#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i "LEM3.INP"
#define f_o ""

#define maxC 100000

typedef map<int,int> Path;
typedef Path::iterator PI;
typedef map<int,Path> Graph;
typedef Graph::iterator GI;

int s,f,n,m;
Graph g;
void readfile(){
  FILE *fi;
  fi=fopen(f_i,"r");
  fscanf(fi,"%d",&n);
  int i,j,v;
  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      fscanf(fi,"%d",&v);
      if(i!=j){
        g[i][j]=v;
      }
    }
  }
  fclose(fi);
}
int dijkstra(int s,int f){
  Path trace,Free,d;
  int x;
  for(x=0;x<n;++x){
    d[x]=maxC;
  }
  d[s]=0;
  int min,u;
  PI i,v;
  do{
    u=0;min=maxC;
    for(i=d.begin();i!=d.end();++i){
      if((Free.find(i->first)==Free.end()) &&i->second<min){
        min=i->second;
        u=i->first;
      }
    }
    if(u==0|| u==f) break;
    Free[u]=0;
    Path p=g[u];
    for(v=p.begin();v!=p.end();++v){
      if(Free.find(v->first)==Free.end()
          &&(d[v->first]>d[u]+v->second)){
        d[v->first]=d[u]+v->second;
        trace[v->first]=u;
      }
    }
  }while(1);
  return d[f];
}
int main(){
  readfile();
  printf("%d",dijkstra(1,2));
}
