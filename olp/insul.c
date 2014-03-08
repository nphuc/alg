#include <stdio.h>
#include <stdlib.h>

#define maxN 100100
#define maxV 10100
int a[maxN],b[maxN],n;
int max;
int c[maxV];
void count_sort(){
  int i,j;
  for(i=1;i<=max;++i) c[i]=0;
  for(j=1;j<=n;++j) c[a[j]]= c[a[j]]+1;
  for(i=1;i<=max;++i) c[i]=c[i]+c[i-1];
  for(j=n;j>0;--j){
    b[c[a[j]]-1] =a[j];
    c[a[j]]=c[a[j]]-1;
  }
  //for(i=0;i<n;++i) printf("%d\n",b[i]);
}
#define max2(a,b) ((a)>(b)?(a):(b))
long sum=0;
int main(){
  scanf("%d",&n);
  int i;
  max=0;
  for(i=1;i<=n;++i){
    scanf("%d",a+i);
    sum+=a[i];
    if(a[i]>max) max=a[i];
  }
  //printf("%ld\n",sum);
  count_sort();
  long s1=0,s2=0;
  int mid=n/2;
  for(i=0;i<mid;++i){
    s1+=b[n-1-i]-b[i];
  }
  /*for(i=0;i<n-1;++i){
    s2+=b[i+1]-b[i];
  }*/
  printf("%ld\n",sum+max2(s1,s2));
  return 0;
}
