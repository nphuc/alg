#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define f_i "QBHEAP.INP"
#define f_o ""
typedef long long ll;
FILE *fi;
typedef map<ll,bool> Map;
typedef Map::iterator MI;
typedef Map::reverse_iterator MRI;
#define maxS 15000
int main(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  char s[25];
  Map m;
  ll n;
  while(fscanf(fi,"%s",s)==1){
    if(s[0]=='+'){
      if(m.size()<maxS){
        sscanf(s+1,"%lld",&n);
        m[n]=true;
      }
    }else{
      if(m.size()>0){
        MI last=m.end();
        --last;
        //printf("erase %lld\n",last->first);
        m.erase(last);
      }
    }
  }
  printf("%lu\n",m.size());
  for(MRI mri=m.rbegin();mri!=m.rend();++mri){
    printf("%lld\n",mri->first);
  }
}
