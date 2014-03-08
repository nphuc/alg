#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i ""
#define f_o ""
typedef long long ll;
#define max 100100
typedef struct str{
  char s[18];
}str;
int cmp(const void *a,const void *b){
  str *s1=(str*)a;
  str *s2=(str*)b;
  return strcmp(s1->s,s2->s);
}
str s[max];
long n;
int main(){
  long i;
  scanf("%ld",&n);
  for(i=0;i<n;++i) scanf("%s",s[i].s);
  qsort(s,n,sizeof(str),cmp);
  str *start=s;
  long cnt;
  for(i=0;i<n;++i){
    if(cmp(s+i,start)!=0){
      cnt=s+i-start;
      if(cnt%2){
        printf("%s",start->s);
        return 0;
      }else{
        start=s+i;
      }
    }
  }
  printf("%s",(s+n-1)->s);
  return 0;
}
