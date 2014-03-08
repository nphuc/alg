#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define f_i "WORDCNT.INP"
FILE *fi;
char *s;
size_t buf_len;
int solve(){
  getline(&s,&buf_len,fi);
  size_t i=0;
  int cnt=1,prevcnt=0,samel=1,res=0;
  for(;;){
    if(i>=buf_len) break;
    if(*(s+i)>='a' && *(s+i) <='z'){
      ++cnt;
    }else{
      if(cnt==prevcnt){
        ++samel;
      }else{
        if(samel>res) res=samel;
        samel=1;
        prevcnt=cnt;
      }
      cnt=1;
    }
    ++i;
  } 
  return res;
}
int main(){
  s=malloc(20100);
  fi=fopen(f_i,"r");
  getline(&s,&buf_len,fi);
  int t;
  sscanf(s,"%d",&t);
  int i;
  for(i=0;i<t;++i){
    printf("%d\n",solve());
  }
  return 0;
}
