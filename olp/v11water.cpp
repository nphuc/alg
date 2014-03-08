#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define f_i "V11WATER.INP"
#define f_o "V11WATER.OUT"

FILE *fi,*fo;
#define maxN 101000
long a[maxN],ml[maxN],mr[maxN],n;
void readfile(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  fscanf(fi,"%ld",&n);
  long i;
  for(i=1;i<=n;++i) fscanf(fi,"%ld",a+i);
  a[0]=0;
  a[n+1]=0;
  fclose(fi);
}
#define min2(a,b) ((a)<(b)?(a):(b))
long long solve(){
  // find max left
  long i;
  ml[0]=0;
  for(i=1;i<=n;++i){
    if(a[i]>ml[i-1]) ml[i]=a[i];
    else ml[i]=ml[i-1];
  }
  mr[n+1]=0;
  for(i=n;i>=1;--i){
    if(a[i]>mr[i+1]) mr[i]=a[i];
    else mr[i]=mr[i+1];
  }
  long t;
  long long s=0;
  for(i=1;i<=n;++i){
   // printf("%ld %ld %ld\n",ml[i-1],a[i],mr[i+1]);
    t=min2(ml[i-1],mr[i+1]);
    if(t>a[i]) {
      s+=t-a[i];
    }
  }
  return s;
}
int main(){
  readfile();
  printf("%lld",solve());
}
