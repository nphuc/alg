#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

FILE *fi,*fo;
#define f_i "VMSORT.INP"
#define f_o "VMSORT.OUT"
typedef map<string,bool> Map;
Map m;
int main(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  int i,n;
  fscanf(fi,"%d",&n);
  for(i=0;i<n;++i){
    int j,c;
    fscanf(fi,"%d",&c);
    char s[25];
    for(j=0;j<c;++j){
      fscanf(fi,"%s",s);
      string t=s;
      m[s]=true;
    }
  }
  printf("%lu",m.size());
}
