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
typedef struct out{
  char s[12];
}out;
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
  char s[15];
  sprintf(s,"%lld",*ni);
  long i=strlen(s);
  printf("%lld",*ni);
  ++ni;
  int j;
  for(;ni!=n.end();++ni){
#if B==1000000000
    sprintf(s,"%09lld",*ni);
    for(j=0;j<9;++j){
      if(i%70==0) printf("\n");
      printf("%c",s[j]);
      ++i;
    }
#else
    printf("%lld",*ni);
#endif
  }
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
int cmp(num &a,num &b){
  if(a.size()!=b.size()){
    return a.size()-b.size();
  }
  NRI ia=a.rbegin(),ib=b.rbegin();
  while(ia!=a.rend()){
    if(*ia!=*ib) return *ia-*ib;
    ++ia;++ib;
  }
  return 0;
}

ll ctoll(char *s,long st,long nd){
  long i;
  ll n=0;
  for(i=st;i<nd;++i){
    n=n*10+*(s+i)-'0';
  }
  return n;
}
num cton(char *s){
  long len=strlen(s);
  long i=len;
  num res;
  while(i>C){
    res.push_front(ctoll(s,i-C,i));
    i-=C;
  }
  if(i==0) return res;
  res.push_front(ctoll(s,0,i));
  rm0(res);
  return res;
}
void daodau(num &n){
  *(n.begin())=-*(n.begin());
}

int main(){
  ll n,p;
  scanf("%lld%lld",&n,&p);
  num a,res;
  a.push_back(n);
  res.push_back(1);
  while(p!=0){
    if(p%2){
      res=mul(res,a);
    }
    a=mul(a,a);
    p=p/2;
  }
  print(res);
}
