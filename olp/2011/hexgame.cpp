#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i "HEXGAME.INP"
#define f_o ""
typedef struct hex{
  /* 0 1 2
   *3 4 5 6
   *7 8 9
   */
  int v[10];
  void left(){
    int t=v[0];
    v[0]=v[3];
    v[3]=v[7];
    v[7]=v[8];
    v[8]=v[5];
    v[5]=v[1];
    v[1]=t;
  }
  void right(){
    int t=v[1];
    v[1]=v[4];
    v[4]=v[8];
    v[8]=v[9];
    v[9]=v[6];
    v[6]=v[2];
    v[2]=t;
  }
  bool operator ==(const hex &o) const{
    int i;
    for(i=0;i<10;++i){
      if (v[i]!=o.v[i]) return false;
    }
  }
}hex;
#define max 1000000
hex m[max];
long mlen,res[max];
void init(){
  hex h;
  h.v[0]=1;h.v[1]=2;h.v[2]=3;
  h.v[3]=8;h.v[4]=0;h.v[5]=0;h.v[6]=0;
  h.v[7]=7;h.v[8]=6;h.v[9]=5;
  m[0]=h;mlen=1;
  res[0]=1;
}
void solve(hex h,long p){
  hex l=h,r=h;
  l.left();
  r.right();
  long i;
  for(i=0;i<mlen;++i){
    if(l==m[i]) goto _next;
  }
  m[mlen]=l;
  res[mlen]=p+1;
  ++mlen;
_next:
  for(i=0;i<mlen;++i){
    if(r==m[i]) goto _exit;
  }
  m[mlen]=l;
  res[mlen]=p+1;
  ++mlen;
  
_exit:;
}
int main(){
  
}
