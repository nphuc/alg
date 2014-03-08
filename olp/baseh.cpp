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
typedef long long ll;
typedef list<int> L;
typedef L::iterator LI;
int main(){
  ll k,h;
  L memo;
  scanf("%lld%lld",&k,&h);
  while(k!=0){
    memo.push_front(k%2);
    k=k/2;
  }
  LI li=memo.begin();
  ll res=1;
  ++li;
  for(;li!=memo.end();++li){
    printf("%d\n",*li);
    res=res*h+(*li);
  }
  printf("%lld",res);
}
