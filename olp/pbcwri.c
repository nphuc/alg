#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i ""
#define f_o ""
#define maxN 3005
#define maxM 3000100
char s1[maxN],s2[maxM];
int c1[177],c2[177];
typedef long long ll;
long n,m;
void init(){
  int i;
  for(i=33;i<177;++i) {
    c1[i]=0;
    c2[i]=0;
  }
  for(i=0;i<n;++i){
    ++c1[s1[i]];
  }
}
int cmp(){
  int i;
  for(i=33;i<177;++i){
    if(c1[i]!=c2[i]) return 0;
  }
  return 1;
}
int main(){
  scanf("%ld%ld",&n,&m);
  scanf("%s%s",s1,s2);
  long i=0,res=0,j;
  init();
  for(j=0;j<n;++j){
    ++c2[s2[j]];
  }
  ++i;
  if(cmp()) ++res;
  while(i+n<=m){
    --c2[s2[i-1]];
    ++c2[s2[i+n-1]];
    if(cmp())++res;
    ++i;
  }
  printf("%ld",res);
  return 0;
}
