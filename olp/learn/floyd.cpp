#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define f_i "FLOYD.INP"
#define f_o ".OUT"
#define maxC 2000000000
typedef map<long,long> Path;
typedef Path::iterator PI;
typedef map<long,Path> Graph;
typedef Graph::iterator GI;
Graph g;
Path trace,d,Free;
FILE *fi;
long n,k;
void readgraph(){
  long i,a,b,v;
  long m;
  fscanf(fi,"%ld%ld%ld",&n,&m,&k);
  for(i=0;i<m;++i){
    fscanf(fi,"%ld%ld%ld",&a,&b,&v);
    g[a][b]=v;
  }
}
void init(long s){
  long i;
  Free.clear();
  trace.clear();
  for(i=1;i<=n;++i){
    d[i]=maxC;
  }
  d[s]=0;
}
long dijkstra(long s,long f){
  long min,u;
  PI i,v;
  init(s);
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
      if(Free.find(v->first)==Free.end()
          &&(d[v->first]>d[u]+g[u][v->first])){
        d[v->first]=d[u]+g[u][v->first];
        trace[v->first]=u;
      }
    }
  }while(1);
  return d[f];
}
#define min2(a,b) ((a)<(b)?(a):(b))
long solve(long k){
  long i,t,res=maxC;
  for(i=1;i<=n;++i){
    if(i!=k){
      t=dijkstra(i,k)+dijkstra(k,i);
      if(t<res) res=t;
    }
  }
  if(res>=maxC) return -1;
  return res;
}

int main(){
  fi=fopen(f_i,"r");
  //fi=stdin;
  long i,j;
  readgraph();
  long x,y,z;
  for(i=0;i<k;++i){
    fscanf(fi,"%ld%ld%ld",&x,&y,&z);
    if(x){
      long r=dijkstra(y,z);
      if(r<0){
        printf("0\n");
      }else{
       long t[200],tl=0;
        while(z!=y){
         t[tl]=trace[z];
         z=t[tl];
         ++tl;
        }
        printf("%ld ",tl);
        for(long tmp=tl-1;tmp>=0;--tmp){
          printf("%ld ",t[tmp]);
        }
        printf("\n");
      }
    }else{
      printf("%ld\n",dijkstra(y,z));
    }
  }
  return 0;
}
