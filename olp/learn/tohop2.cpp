#include <cstdio>

int x[100],n,k;
int main(){
  n=5;k=3;
  int i,j;
  for(i=0;i<k;++i) x[i]=i;
  for(;;){
    for(i=0;i<k;++i){
      printf("%4d",x[i]);
    } 
    printf("\n");
    i=k-1;
    while(i>=0 && x[i]==n+i-k)--i;
    ++x[i];
    if(i<0) break;
    for(j=i+1;j<k;++j) x[j]=x[j-1]+1;
  }
}
