#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
static inline ll mylog2(const ll x){
  ll y;
  asm(
      "\tbsr %1,%0\n":"=r"(y):"r"(x)
     );
  return y;
}
int main(){
}
