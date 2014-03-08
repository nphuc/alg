#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 110
#define f_i "VMUNCH.INP"
char map[maxN][maxN];
int cost[maxN][maxN];
int r,c;
typedef struct point point;
struct point{
  int x,y;
};
FILE *fi;
void init(){
  int i,j;
  for(i=1;i<=r;++i){
    for(j=1;j<=c;++j){
      cost[j][i]=0;
    }
  } 
}
point B,C;
void read(){
  fscanf(fi,"%d%d",&r,&c);
  int i,j;
  for(j=1;j<=r;++j){
    i=1;
    while(i<=c){
      fscanf(fi,"%c",map[j]+i);
      if(map[j][i]=='.'||map[j][i]=='*'){

      } else if(map[j][i]=='B'){
        B.x=i;
        B.y=j;
      }else if(map[j][i]=='C'){
        C.x=i;
        C.y=j;
      }else{
        goto next;
      }
      printf("[%c]",map[j][i]);
      ++i;
next:;
    }
    printf("\n");
  }
}

point queue[maxN*maxN];
int qlen=0;
void BFS(){
    
}
int main(){
  fi=fopen(f_i,"r");
  read();
  init();
  printf("%d %d %d %d\n",B.x,B.y,C.x,C.y);
  return 0;
}
