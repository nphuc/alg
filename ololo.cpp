#include <cstdio>
#include <cstdlib>
#include <map>

#define isdigit(c) ((c)<='9' && (c)>='0')
using namespace std;
typedef map<long,int>memo;
int main(){
    register long i;
    long t;
    memo m;
    scanf("%ld",&t);
    i=t;
    while(i--){
        scanf("%ld",&t);
        m[t]++;
    }
    for(memo::iterator it=m.begin();it!=m.end();++it){
        if(it->second%2!=0){
            printf("%ld",it->first);
            return 0;
        }
    }
}
