#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "PBCWATER.INP"
#define f_o ""
#define max 1005
#define min2(a,b) ((a)<(b)?(a):(b))
#define min4(a,b,c,d) min2(min2(a,b),min2(c,d))
#define minxy(a,x,y) min4(a[y-1][x],a[y+1][x],a[y][x-1],a[y][x+1])
#define maxv 1000000
typedef long long ll;
int a[max][max],m,n,r[max][max];
void readfile(){
  FILE *fi=fopen(f_i,"r");
  fscanf(fi,"%d%d",&m,&n);
  int j,i;
  for(j=1;j<=m;++j){
    for(i=1;i<=n;++i){
      fscanf(fi,"%d",&(a[j][i]));
    }
  }
  fclose(fi);
}
void A1P(int *a,int n){
  int i;
  for(i=0;i<n;++i){
    printf("%8d",*(a+i));
  }
  printf("\n");
}
void A2P(int **a,int m,int n){
  int j;
  for(j=0;j<m;++j) A1P(*(a+j),n);
}
void init(){
  int i,j;
  for(i=0;i<=n+1;++i){
    a[0][i]=maxv;
    r[0][i]=maxv;
    r[m+1][i]=maxv;
    a[m+1][i]=maxv;
  }
  for(j=1;j<=m;++j){
    a[j][0]=maxv;
    r[j][0]=maxv;
    a[j][n+1]=maxv;
    r[j][n+1]=maxv;
  }
}
void solve(){
  int i,j;
  int t,minx,miny,maxx,maxy;
  for(t=1;t<=min2(m,n)+1;++t){
      minx=t;
      miny=t;
      maxx=n+1-t;
      maxy=m+1-t;
      for(i=minx;i<=maxx;++i){
      }
      for(j=miny+1;j<maxy;++j){
      }
  }
}
int main(){
  readfile();
  init();
  int i,j;
  for(j=0;j<=m+1;++j){
    A1P(a[j],n+2);
  }
 // solve();
  for(j=0;j<=m+1;++j){
    A1P(r[j],n+2);
  }
  return 0;
}
