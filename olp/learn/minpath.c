#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

#define max 100
#define maxC 100000
#define f_i "MINPATH.INP"
#define f_o "MINPATH.OUT"
int c[max][max];
int d[max];
int trace[max];
int Free[max];
int n,s,f;
void loadgraph(){
  FILE *fi;
  fi=fopen(f_i,"r");
  int u,v,i,m;
  fscanf(fi,"%d%d%d%d",&n,&m,&s,&f);
  for(u=1;u<=n;++u){
    for(v=1;v<=n;++v){
      if(u==v) c[u][v]=0;else c[u][v]=maxC;
    }
  }
  for(i=1;i<=m;++i){
    fscanf(fi,"%d%d",&u,&v);
    fscanf(fi,"%d",&(c[u][v]));
  }
  fclose(fi);
}

void init(){
  int i;
  for(i=1;i<=n;++i) {
    d[i]=maxC;
    Free[i]=1;
  }
  d[s]=0;
}
void dijkstra(){
  int i,u,v,min;
  int count=0;
  do{
    u=0;min=maxC;
    for(i=1;i<=n;++i){
      if(Free[i] && d[i]<min){
        min=d[i];
        u=i;
      }
    }
    printf("%d min=%d\n",u,min);
    if(u==0 || u==f) break;
    Free[u]=0;
    for(v=1;v<=n;++v){
      printf("loop: %d\n",++count);
      if(Free[v] && (d[v]>d[u]+c[u][v])){
        d[v]=d[u]+c[u][v];
        trace[v]=u;
      }
    }
  }while(1);
}
void print(){
  FILE *fo=fopen(f_o,"w");
  if(d[f]==maxC){
    fprintf(fo,"There no path from %d to %d\n",s,f);
  }else{
    fprintf(fo,"Distance: %d -> %d: %d\n",s,f,d[f]);
    while(f!=s){
      fprintf(fo,"%d<-",f);
      f=trace[f];
    }
    fprintf(fo,"%d",s);
  }
  fclose(fo);
}
int main(){
  loadgraph();
  init();
  int i,j;
  //for(i=1;i<=n;++i) P1AI(c[i]+1,n);
  P1AI(d+1,n);
  dijkstra();
  print();
}
