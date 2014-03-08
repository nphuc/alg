#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define f_i "MINPATH.INP"
#define f_o "MINPATH.OUT"
#define maxC 2000000000

typedef map<int,int> Path;
typedef Path::iterator PI;
typedef map<int,Path> Graph;
typedef Graph::iterator GI;

int s,f,n,m;
Graph g;
Path trace,d,Free;
void readfile(){
  FILE *fi;
  fi=fopen(f_i,"r");
  fscanf(fi,"%d%d%d%d",&n,&m,&s,&f);
  int i,a,b,v;
  for(i=0;i<m;++i){
    fscanf(fi,"%d%d%d",&a,&b,&v);
    g[a][b]=v;
  }
  fclose(fi);
}
void init(){
  int i;
  for(i=1;i<=n;++i){
    d[i]=maxC;
  }
  d[s]=0;
}
void dijkstra(){
  int min,u;
  PI i,v;
  do{
    u=0;min=maxC;
    for(i=d.begin();i!=d.end();++i){
      if((Free.find(i->first)==Free.end()) &&d[i->first]<min){
        min=d[i->first];
        u=i->first;
      }
    }
    if(u==0|| u==f) break;
    Free[u]=0;
    for(v=g[u].begin();v!=g[u].end();++v){
      {static size_t _l=0;printf("%lu\n",++_l);}
      if(Free.find(v->first)==Free.end()
          &&(d[v->first]>d[u]+g[u][v->first])){
          d[v->first]=d[u]+g[u][v->first];
          trace[v->first]=u;
      }
    }
  }while(1);
}
void print(){
  FILE *fo=fopen(f_o,"w");
  if(d[f]==maxC){
    fprintf(fo,"No path %d to %d",s,f);
  }else{
    fprintf(fo,"Distance %d to %d: %d\n",s,f,d[f]);
    while(f!=s){
      fprintf(fo,"%d<-",f);
      f=trace[f];
    }
    fprintf(fo,"%d",s);
  }
  fclose(fo);
}
int main(){
  readfile();
  init();
  dijkstra();
  print();
}
