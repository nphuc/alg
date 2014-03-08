#include <cstdio>
#include <cstdlib>
#include <map>
#include <list>
#include <algorithm>

using namespace std;
#define f_i "VMUNCH.INP"
#define f_o "VMUCNH.OUT"

FILE *fi,*fo;
#define maxN 120
#define maxC 120120

int mp[maxN][maxN],mx,my;

typedef struct point{
  int x,y;
  point(int xx,int yy){x=xx;y=yy;};
  point(){};
  bool operator<(const point&o) const{
    if(y<o.y) return true;
    if(y==o.y) return x<o.x;
    return false;
  }
  bool operator>(const point&o)const{
    if(y>o.y) return true;
    if(y==o.y) return x>o.x;
    return false;
  }
  bool operator==(const point &o)const{
    return y==o.y&& x==o.x;
  } 
 /* point operator=(const point &o){
    return point(o.x,o.y);
  }*/
  void p() const{
    printf("point {%d,%d}\n",x,y);
  }
/*  bool operator()(const point &a,const point &b){
    return a<b;
  }*/
}point;

typedef map<point,int> Path;
typedef Path::iterator PI;

typedef map<point,Path> Graph;
typedef Graph::iterator GI;

point s,f;
Graph g;
void PP(Path &p){
  PI pi;
  for(pi=p.begin();pi!=p.end();++pi){
    printf("%d %d: %d\n",pi->first.x,pi->first.y,pi->second);
  }
}
void GP(Graph &g){
  GI gi;
  for(gi=g.begin();gi!=g.end();++gi){
    printf("from: %d %d\n",gi->first.x,gi->first.y);
    PP(gi->second);
  }
} 
void readfile(){
 // fi=fopen(f_i,"r");
  fi=stdin;
  fscanf(fi,"%d%d",&my,&mx);
  int i,j;
  char c;
  for(j=1;j<=my;++j){
    i=1;
    for(;;){
      fscanf(fi,"%c",&c);
      switch(c){
        case 'B':
          f=point(i,j);
          mp[j][i]=1;
          ++i;
          break;
        case 'C':
          s=point(i,j);
          mp[j][i]=1;
          ++i;
          break;
        case '.':
          mp[j][i]=1;
          ++i;
          break;
        case '*':
          mp[j][i]=0;
          ++i;
          break;
      }
      if(i>mx) break;
    }
  }
  fclose(fi);
  /* ***************************************** */
  point a,b;
  int t,cnt;
  Path p;
  for(j=1;j<=my;++j){
    for(i=1;i<=mx;++i){
      if(mp[j][i]){
        p.clear();
        a=point(i,j);
        if(mp[j][i-1]){
          b=point(i-1,j);
          p[b]=1;
        }
        if(mp[j][i+1]){
          b=point(i+1,j);
          p[b]=1;
        } 
        if(mp[j-1][i]){
          b=point(i,j-1);
          p[b]=1;
        }
        if(mp[j+1][i]){
          b=point(i,j+1);
          p[b]=1;
        }
        g[a]=p;
      }
    }
  }
}

Path d,Free;
void init(){
  int i,j;
  point t;
  for(j=1;j<=my;++j){
    for(i=1;i<=mx;++i){
      if(mp[j][i]){
        t=point(i,j);
        d[t]=maxC;
      }
    }
  }
  d[s]=0;
}
void dijkstra(){
  int min;
  point u;
  point zero(0,0);
  PI pi,v;
  Path p;
  do{
    u=zero;
    min=maxC;
    for(pi=d.begin();pi!=d.end();++pi){
      if((Free.find(pi->first)==Free.end()) &&pi->second<min){
        min=pi->second;
        u=pi->first;
      }
    }
    if(u==zero|| u==f) break;
    Free[u]=0;
    p=g[u];
    for(v=p.begin();v!=p.end();++v){
      if(Free.find(v->first)==Free.end() &&
          (d[v->first]>d[u]+v->second)){
        d[v->first]=d[u]+v->second;
      }
    }
  }while(1);
}
int main(){
  readfile();
  int i,j;
  init();
  dijkstra();
  if(d[f]!=maxC){
    printf("%d",d[f]);
  }else{
    printf("%d",-1);
  }
}
