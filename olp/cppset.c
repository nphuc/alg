#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <limits.h>
#define f_i ""
#define f_o ""
typedef long long ll;
long x[300100],nlen,slen,ndel;
char s[300100][12];
int cmp(const void *a,const void *b){
  long d=*(long*)a-*(long*)b;
  return d>0?1:d<0?-1:0;
}
int main(){
  nlen=0;slen=0,ndel=0;
  int cmd;
  long t,*r;
  for(;;){
    scanf("%d",&cmd);
    switch(cmd){
      case 0: goto _out;break;
      case 1:
              scanf("%ld",&t);
              x[nlen]=t;
              ++nlen;
              qsort(x,nlen,sizeof(long),cmp);
              break;
      case 2:
              scanf("%ld",&t);
              r=(long*)bsearch(&t,x+ndel,nlen-ndel,sizeof(long),cmp);
              while( *(r)==t &&(r-x-ndel)>=0) {
                *r=LONG_MIN;
                --r;
              }
              while(*(r)==t && r<=x+nlen) {
                *r=LONG_MIN;
                ++r;
              } 
              qsort(x,nlen,sizeof(long),cmp);
              break;
      case 3:
              if(nlen-ndel<=0){
                strcpy(s[slen],"empty");
              }else{
                sprintf(s[slen],"%ld",x[ndel]);
              }
              ++slen;
              break;
      case 4:
              if(nlen-ndel<=0){
                strcpy(s[slen],"empty");
              }else{
                sprintf(s[slen],"%ld",x[nlen-1]);
              }
              ++slen;
              break;
      case 5:
            
    };
  }
_out:
  return 0;
}
