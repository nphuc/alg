#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "fibo.h"
#define MAX_SIZE 1010

typedef long long ll;
typedef struct edge{
  char i[MAX_SIZE];
  ll v[MAX_SIZE];
  int s;
}edge;

typedef struct graph{
  char i[MAX_SIZE];
  edge v[MAX_SIZE];
  int s;
}graph;
#define has(g,id) ((g).i[id])
#define index(g,id) ((g).v[id])
#define pute(e,k,v) do{++(e).s;index(e,k)=v;has(e,k)=1;}while(0)
graph g;
edge e;
long m,n;
ll res[MAX_SIZE][MAX_SIZE];
FILE *fi;

#define MAX 99999999999
void dijkstra(long s){
  heap* pq=heap_init();
  elem* entries[n+1];
  edge result;
  memset(result.i,0,n+1);
  int i,ml[n+1];
  for(i=1;i<=n;++i){
    ml[i]=i;
    entries[i]=heap_insert(&pq,MAX,ml+i);
    //printf("%d %lld\n",*(int*)entries[i]->value,entries[i]->key);
  }
  heap_decrease_key(&pq,entries[s],0);
  //printf("%d %lld\n",*(int*)entries[s]->value,entries[s]->key);
  //printf("decrease ok\n");
  while(!is_empty(pq)){
    data curr=heap_extract_min(&pq);
    //print_data(curr);
    int cv=*(int*) curr.value;
    result.i[cv]=1;
    result.v[cv]=curr.key;
    for(i=1;i<=n;++i){
      if(has(result,i)) continue;
      if(!has(g.v[cv],i)){
        continue;
      }
      printf("path %d ->%d\n",cv,i);
      ll pathCost=index(result,i)+ g.v[cv].v[i];
      elem* dest=entries[i];
      printf("pC=%lld key=%lld\n",pathCost,dest->key);
      if( dest->key> pathCost){
        printf("desc key\n");
        heap_decrease_key(&pq,dest,pathCost);
      }
    }
  }
  for(i=1;i<=n;++i){
    res[s][i]=result.v[i];
  }
}
void solve(){
  fscanf(fi,"%ld%ld",&n,&m);
  long i;
  g.s=n;
  for(i=1;i<=n;++i){
    index(g,i).s=0;
  }
  long u,v,c;
  for(i=0;i<m;++i){
    fscanf(fi,"%ld%ld%ld",&u,&v,&c);
    pute(index(g,u),v,c);
    printf("%ld %ld %ld\n",u,v ,c);
  }
  for(i=1;i<=n;++i){
    dijkstra(i);
  }
}
int main(){
  //fi=stdin;
  fi=fopen("FBH.INP","r");
  int i,test;
  fscanf(fi,"%d",&test);
  for(i=0;i<test;++i)solve();
  return 0;
}
