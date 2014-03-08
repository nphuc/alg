#include <cstdio>
#include <cstdlib>
#include <list>
#include <cstring>

using namespace std;
#define B 1000000000
#define C 9
#define f_i "BIGNUM.INP"
typedef long long ll;
typedef list<ll> num;
typedef num::iterator NI;
typedef num::reverse_iterator NRI;
void rm0(num &n){
  while((*(n.begin())==0) && (n.size()>1)){
    n.pop_front();
  }
}
num add(num &a,num &b){
  NRI ia=a.rbegin(),ib=b.rbegin();
  ll sodu=0;
  num res;
  while(ia!=a.rend() && ib!=b.rend()){
    sodu+=*ia+*ib;
    res.push_front(sodu%B);
    sodu/=B;
    ++ia;
    ++ib;
  }
  while(ia!=a.rend()){
    sodu+=*ia;
    res.push_front(sodu%B);
    sodu/=B;
    ++ia;
  }
  while(ib!=b.rend()){
    sodu+=*ib;
    res.push_front(sodu%B);
    sodu/=B;
    ++ib;
  }
  while(sodu!=0){
    res.push_front(sodu%B);
    sodu/=B;
  }
  rm0(res);
  return res;
}
void print(num &n){
  NI ni=n.begin();
  printf("%lld",*ni);
  ++ni;
  for(;ni!=n.end();++ni){
#if B==1000000000
    printf("%09lld",*ni);
#else
    printf("%lld",*ni);
#endif
  }
  printf("\n");
}
int eq0(num &n){
  return n.size()==1 && *(n.begin())==0;
}
num mul1(num &a,ll n){
  ll sd=0;
  NRI ia=a.rbegin();
  num res;
  while(ia!=a.rend()){
    sd=*ia*n+sd;
    res.push_front(sd%B);
    sd/=B;
    ++ia;
  }
  while(sd!=0){
    res.push_front(sd%B);
    sd/=B;
  }
  rm0(res);
  return res;
}
num mul(num &a,num &b){
  NI ib=b.begin();
  num res,t;
  while(ib!=b.end()){
    res.push_back(0);
    t=mul1(a,*ib);
    res=add(t,res);
    ++ib;
  }
  rm0(res);
  return res;
}
num sub(num &a,num &b){
  num c;
  NRI ia=a.rbegin(),ib=b.rbegin();
  ll memo=0,t,t1,t2;
  while(!(ib==b.rend())){
    t=*ia-*ib+memo;
    if(t<0){
      t=t+B;
      c.push_front(t);
      memo=-1;
    }else{
      c.push_front(t);
      memo=0;
    }
    ++ia;++ib;
  }
  while(ia!=a.rend()){
    t=*ia+memo;
    if(t<0){
      t=t+B;
      c.push_front(t);
      memo=-1;
    }else{
      c.push_front(t);
      memo=0;
    }
    ++ia;
  }
  rm0(c);
  return c;
} 
void daodau(num &n){
  *(n.begin())=-*(n.begin());
}
num ton(long n){
  num res;
  while(n>C){
    res.push_back(111111111);
    n-=C;
  }
  long t=0,i;
  if(n>0){
    for(i=0;i<n;++i){
      t=t*10+1;
    }
    res.push_front(t);
  }
  return res;
}
int main(){
  int k,i;
  long n;
  num a,r;
  scanf("%d",&k);
  for(i=0;i<k;++i){
    scanf("%ld",&n);
    a=ton(n);
    r=mul(a,a);
    print(r);
  }

}
