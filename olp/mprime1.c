#include <stdio.h>
#include <stdlib.h>

#define maxV 11000
int p[2000],plen;
void init(){
  p[0]=2;
  p[1]=3;
  int t;
  plen=2;
  t=p[plen-1];
  int i;
  while(t*t<=maxV){
    ++t;
    i=0;
    while(p[i]*p[i]<=t){
      if(t%p[i]==0) goto next1;
      ++i;
    }
    p[plen]=t;
    ++plen;
next1:;
  }
  int old=plen;
  while(p[plen-1]<=maxV){
    ++t;
    i=0;
    while(p[i]*p[i]<=t &&i<old){
      if(t%p[i]==0) goto next2;
      ++i;
    }
    p[plen]=t;
    ++plen;
next2:;
  }
}

int solve(int n){
  int i,j,s,len=1,res=0;
  for(len=1;len<=plen;++len){
    for(i=0;i+len<plen;++i){
      s=0;
      for(j=0;j<len;++j) s+=p[i+j];
      if(s==n)++res;
      if(s>n) goto next;
    }
next:;
  }
  return res;
}
int main(){
  init();
  int n;
  while(scanf("%d",&n)==1 && n!=0){
    printf("%d\n",solve(n));
  }
  return 0;
}
