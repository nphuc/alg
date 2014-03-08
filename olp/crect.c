#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i "CRECT.INP"
#define f_o ""
#define max 410
typedef long long ll;
char map[max][max];
int m,n;
void readfile(){
  FILE *fi=fopen(f_i,"r");
  char c;
  fscanf(fi,"%d%d",&m,&n);
  int i,j;
  for(j=0;j<m;++j){
    i=0;
    for(;;){
      fscanf(fi,"%c",&c);
      if(i>=n) break;
      if(c>='A' &&c<='E') {
        map[j][i]=c;
        ++i;
      }
    }
  }
  fclose(fi);
}
#define CHECK(x,y) ((x)>=0 && (x)<n &&(y)>==0 &&(y)<m)
long res;
int main(){
  readfile();
  return 0;
}
