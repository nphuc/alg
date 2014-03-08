#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct num{
  int a[65];
  int n;
}num;
num ton(ll n){
  num res;
  res.n=0;
  while(n!=0){
    res.a[res.n]=n%10;
    n/=10;
    ++res.n;
  } 
  return res;
}
ll tos2(num *n){
  ll res=0;
  int i;
  for(i=0;i<n->n;++i){
    res+=n->a[i]*n->a[i];
  }
  return res;
}
static ll mem[9]={4,16,37,58,89,145,42,20};
int isclear(ll in){
  num n=ton(in);
  for(;;){
    ll t=tos2(&n);
    if(t==1) return 1;
    int j;
    for(j=0;j<9;++j){
      if(t==mem[j]) return 0;
    }
    n=ton(t);
  }
}
int main(){
  int i,t;
  ll n,m;
  scanf("%d",&t);
  for(i=0;i<t;++i){
    if(isclear(i)){
      printf("clear %d\n",i);
    }else{
      printf("non-clear %d\n",i);
    }
  }
  return 0;
}
