#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isdigit(c) ((c)>='0' && (c)<='9')
#define chartonum(c) ((c)-'0')
typedef struct mass{
  int c,h,o;
}mass;
mass simple(char *s,int n){
  int i=0;
  mass res={.c=0,.h=0,.o=0};
  if(n<=0) return res;
  for(;;){
    if(i>=n) break;
    switch(*(s+i)){
      case 'C':
        if(i+1<n && isdigit(*(s+i+1))){
          res.c+=chartonum(*(s+i+1));
          i+=2;
        }else{
          res.c+=1;
          ++i;
        }
        break;
      case 'H':
        if(i+1<n && isdigit(*(s+i+1))){
          res.h+=chartonum(*(s+i+1));
          i+=2;
        }else{
          res.h+=1;
          ++i;
        }
        break;
      case 'O':
        if(i+1<n && isdigit(*(s+i+1))){
          res.o+=chartonum(*(s+i+1));
          i+=2;
        }else{
          res.o+=1;
          ++i;
        }
        break;
    }
  }
  return res;
}
mass solve(char *s,int n,int prevlv){
  int i;
  int j=n-1;
  for(i=0;i<n;++i) if(*(s+i)=='(') goto hard;
  mass res={.o=0,.h=0,.c=0};
  mass r=simple(s,n);
  mass left,right,res2={.o=0,.h=0,.c=0};
  res.c+=r.c*prevlv;
  res.h+=r.h*prevlv;
  res.o+=r.o*prevlv;
  return res;
hard:
  while(*(s+j)!=')') --j;
  if(j+1<n && isdigit(*(s+j+1))){
    prevlv=prevlv*chartonum(*(s+j+1));
    left=simple(s,i-1);
    right=simple(s+j+2,n-j-1);
    res2=solve(s+i+1,j-i-2,prevlv);
  }else{
    left=simple(s,i-1);
    right=simple(s+j+1,n-j);
    res2=solve(s+i+1,j-i-2,prevlv);
  }
  res2.c+=(left.c+right.c)*prevlv;
  res2.h+=(left.h+right.h)*prevlv;
  res2.o+=(left.o+right.o)*prevlv;
  return res2;
}
int main(){
  char *s="CH(CO2H)3";
  mass res=solve(s,strlen(s),1);
  printf("%d\n%d\n%d\n",res.c,res.h,res.o);
  return 0;
}
