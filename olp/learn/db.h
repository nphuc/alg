
#include <stdio.h>
#include <stdlib.h>

#ifndef _db_h_
#define _db_h_

void P1AI(int *a,size_t n){
  size_t i;
  for(i=0;i<n;++i){
    printf("%8d",*(a+i));
  }
  printf("\n");
}
void P2AI(int **a,size_t m,size_t n){
  size_t i,j;
  for(j=0;j<m;++j){
      P1AI(*(a+j),n);
  }
}
#endif
