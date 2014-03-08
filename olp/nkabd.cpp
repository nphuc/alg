#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define f_i ""
#define f_o ""
int main(){
  long l,r;
  scanf("%ld%ld",&l,&r);
  long i,res=0,s,j,c2;
  for(i=l;i<=r;++i){
    s=1;
    j=2;
    while(j*j<i){
      if(i%j==0) s+=j+i/j;
      ++j;
    }
    if(j*j==i) s+=j;
    if(s>i) {
      ++res;
    }
  }
  printf("%ld",res);
}
