#include <cstdio>
#include <cstdlib>

#define max 100
int n,k,x[max];

void Try(int i){
  int j,t;
  if(i==k){
    for(t=0;t<k;++t){
      printf("%4d",x[t]);
    }
    printf("\n");
    return;
  }
  for(j=x[i-1]+1;j<=n+i-k;++j){
    x[i]=j;
    Try(i+1);
  }
}
int main(){
  n=5;
  for(k=1;k<=n;++k){
    // bat dau in ra to hop k cua n phan tu
    int i;
    for(i=0;i<=n-k;++i){
      x[0]=i;
      Try(1);
    }
  }
}
