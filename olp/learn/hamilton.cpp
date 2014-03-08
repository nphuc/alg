#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i "HAMILTON.INP"
#define f_o ""

#define max 100
int a[max][max],
    Free[max],
    x[max],n;
FILE *fi,*fo;
void readfile(){
  fi=fopen(f_i,"r");
  int i,j,m,u,v;
  fscanf(fi,"%d%d",&n,&m);
  for(j=1;j<=m;++j){
    fscanf(fi,"%d%d",&u,&v);

    a[u][v]=1;
    a[v][u]=1;
  }
  fclose(fi);
}
void print(){
  int i;
  for(i=1;i<=n;++i) printf("%4d",x[i]);
  printf("\n");
}
void Try(int i){
   int j;
   for(j=1;j<=n;++j){
    if(Free[j] && a[x[i-1]][j]){
      x[i]=j;
      if(i<n){
        Free[j]=0;
        Try(i+1);
        Free[j]=1;
      }else{
        print();
      }
    }
   }
}
int main(){
  readfile();
  int i;
  for(i=1;i<=n;++i){
    Free[i]=1;
  }
  x[1]=1; Free[1]=0;
  Try(2);
}
