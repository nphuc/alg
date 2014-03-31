#include <stdio.h>
int main(){
  long i;
  long long s=0;
  for(i=0;i<=100000000;++i){
    //printf("%ld\n",i);
    s+=i;
  }
  return 0;
}
