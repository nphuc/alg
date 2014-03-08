#include <stdio.h>
#include <stdlib.h>

int f[200],n,m[200];
void init(){
  f[1]=0;
  n=2;
  int i,next=-1; /* -1-l 1-r*/
  for(i=2;i<=31;++i){
    f[n]=next;
    f[n+1]=0;
    next=-next;
    n+=2;
  }
  m[1]=2; /*2-D 3-U*/
  i=2;
  while(i<n){
    if(f[i]==-1){
      m[i]=2;
      m[i+1]=3;
    }else{
      m[i]=3;
      m[i+1]=2;
    }
    i+=2;
  }
}
int get(int a,int i){
  return m[2*a-i]; /*2n+2 */
}
int main(){
  init();
  int a,i;
  while(scanf("%d%d",&a,&i)==2){
    if(a==0||i==0) break;
    printf("%s\n",get(a,i)==2?"D":"U");
  }
  return 0;
}
