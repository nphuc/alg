#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i ""
#define f_o ""

#define maxN 1000100
long a[maxN],s[maxN],m,n;
int cmp(const void *a,const void *b){
  long d=*(long*)a-*(long*)b;
  return d>0?-1:d<0?1:0;
}
int main(){
  scanf("%ld",&n);
  long i;
  for(i=0;i<n;++i){
    scanf("%ld",a+i);
  }
  qsort(a,n,sizeof(long),cmp);
  s[0]=a[0];
  m=s[0];

  for(i=0;i<n;++i) printf("a[%li]=%ld\n",i,a[i]);
  for(i=1;i<n;++i){
    if(i%2==1){
      s[i]=s[i-1]-a[n-i/2-1];
      printf("-%ld\n",a[n-i/2-1]);
    }else{
      s[i]=s[i-1]+a[i/2];
      printf("%ld\n",a[i/2]);
    }
    if(m<s[i]) m=s[i];
  }
  for(i=0;i<n;++i) printf("s[%ld]=%ld\n",i,s[i]);
}
