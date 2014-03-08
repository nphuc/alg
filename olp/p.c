#include <stdio.h>

int main(){
  long i,n=30000;
  FILE *fo=fopen("TREENUM.INP","w");
  fprintf(fo,"%ld\n",n);
  for(i=0;i<n;++i){
    fprintf(fo,"9223372036854775808\n");
  }
  fclose(fo);
  return 0;
}
