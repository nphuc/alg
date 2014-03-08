#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i ""
#define f_o ""
#define max 1000100
typedef long long ll;
long d[max],dlen,slen;
char s[max],s2[5];
ll  solve1(){
  long c=0;
  long i;
  ll res=0,t=0;
  dlen=0;
  for(i=0;i<slen;++i){
    if(s[i]==s2[0]){
      d[dlen]=c;
      c=0;
      ++dlen;
    }else if(s[i]==s2[1]){
      ++c;
    }
  }
  d[dlen]=c;
  ++dlen;
  for(i=dlen-1;i>0;--i){
    t=t+d[i];
    res+=t;
  }
  return res;
}
ll solve2(){
  ll res=0;
  long i;
  for(i=0;i<slen;++i){
    if(s[i]==s2[0]) ++res;
  }
  return res*(res-1)/2;
}
int main(){
  char c;
  for(;;){
    scanf("%c",&c);
    if(c<32) break;
    s[slen]=c;
    ++slen;
  }
  scanf("%c",s2);
  scanf("%c",s2+1);
  if(s2[0]!=s2[1]){
    printf("%lld",solve1());
  }else{
    printf("%lld",solve2());
  }
  return 0;
}
