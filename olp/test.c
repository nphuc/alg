#include <stdio.h>

int main(){
  int c;
  for(;;){
    scanf("%d",&c);
    if(c==42) break;
    fprintf(stdout,"%d\n",c);
  }
  return 0;
}
