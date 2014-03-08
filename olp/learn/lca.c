#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i "LCA.INP"
#define f_o ""
#define nmax 200100
typedef long long ll;
typedef struct mg{
  long g,cs,kc;
}mg;
long n,k,i,j,x,y;
char Free[nmax];
FILE *fi;
long d[nmax],cha[nmax];
mg a[nmax];
long sl[nmax/2+1];
long b[nmax][20];
long lg;
void doc(){
  fi=fopen(f_i,"r");
  fscanf(fi,"%ld%ld",&n,&k);
  for(i=1;i<=k;++i) sl[i]=0;
  for(i=1;i<=n;++i){
    fscanf(fi,"%ld%ld",&x,&y);
    cha[i]=y;
    a[i].g=x;
    ++sl[x];
  }
  lg=log(n)/log(2)+1;
}
long dfs(long u){
  long v;
  Free[u]=0;
  if(u==0) return 0;
  if(!Free[cha[u]]){
    d[u]=d[cha[u]]+1;
    return d[u];
  }else{
    d[u]=dfs(cha[u])+1;
  }
  return d[u];
}
void tinh(){
  for(i=1;i<=n;++i) Free[i]=1;
  Free[0]=0;
  for(i=1;i<=n;++i) if(Free[i]) d[i]=dfs(i);
}
void create(){
  b[0][0]=0;
  for(i=1;i<=n;++i)b[i][0]=cha[i];
  for(j=1;j<=lg;++j){
    for(i=0;i<=n;++i){
      b[i][j]=b[b[i][j-1]][j-1];
    }
  }
}
char getbit(long k,long x){
  return (x>>(k-1))&1;
}
long lca(long u,long v){
  long t,bit,k;
  if(d[u]>=d[v]){
    if(d[u]>d[v]){
      t=d[u]-d[v];
      for(bit=lg;bit>0;--bit){
        if(getbit(bit,t)==1){
          u=b[u][bit-1];
        }
      }
      for(k=lg;k>=0;--k){
        if(b[u][k]!=b[v][k]){
          u=b[u][k];
          v=b[v][k];
        }else{
          return b[u][k];
        }
      }
    }
    if(u==v) return u;
  }
  return lca(v,u);
}
long kc(long u,long v){
  long tt;
  tt=lca(u,v);
  return d[u]+d[v]-2*d[tt];
}
int main(){
  doc();
  tinh();
 printf("%ld",kc(2,1));
  return 0;
}
