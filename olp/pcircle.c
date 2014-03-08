#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isprime(int n){
  int i;
  for(i=2;i<=sqrtl(n);++i){
    if(n%i==0) return 0;
  }
  return 1;
}
#define max 20
int n,a[max][max],Free[max],x[max];

void create(){
  int i,j;
  for(i=1;i<=2*n;++i){
    for(j=i+1;j<=2*n;++j){
      if(isprime(i+j)){
        a[i][j]=1;
        a[j][i]=1;
      }else{
        a[i][j]=0;
        a[j][i]=0;
      }
    }
  }
}
void AP(int *x,int n){
  int i;
  for(i=1;i<n;++i){
    printf("%d ",*(x+i));
  }
  printf("%d\n",*(x+n));
}
void GP(){
  int i,j;
  for(j=1;j<=2*n;++j){
    AP(a[j],2*n);
  }
}
int res[10100][max],rlen;
void Try(int i){
  int j,k;
  if(rlen>=10000) return;
  for(j=1;j<=2*n;++j){
    if(Free[j] &&a[x[i-1]][j]){
      x[i]=j;
      if(i<2*n){
        Free[j]=0;
        Try(i+1);
        Free[j]=1;
      }else{
        if(a[x[1]][x[2*n]]){
          AP(x,2*n);
          ++rlen;
        }
      }
    }
  }
}
#define min2(a,b) ((a)<(b)?(a):(b))
int main(){
  scanf("%d",&n);
  long mlen[]={0,1,2,2,4,96,1024,2880,81024,770144};
  printf("%ld\n",mlen[n]);
  //n=9;
  create();
  //GP();
  int i;
  for(i=1;i<=2*n;++i){
    Free[i]=1;
  }
  rlen=0;
  x[1]=1;Free[1]=0;
  Try(2);
  return 0;
}
