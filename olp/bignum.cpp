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
  num a,b,ad,sb,ml;
  FILE *fi;
  //fi=fopen(f_i,"r");
  fi=stdin;
  char s1[1010],s2[1010];
  fscanf(fi,"%s",s1);
  fscanf(fi,"%s",s2);
  fclose(fi);
  int d1,d2;
  if(s1[0]=='-') {
    d1=1;a=cton(s1+1);
  }else{
    d1=0;a=cton(s1);
  }
  if(s2[0]=='-') {
    d2=1;b=cton(s2+1);
  }else{
    d2=0;b=cton(s2);
  }
  if(d1==0 &&d2==0){
    ad=add(a,b);
    if(cmp(a,b)>=0){
      sb=sub(a,b);
    }else{
      sb=sub(b,a);
      daodau(sb);
    }
    ml=mul(b,a);
  }else if(d1==0 &&d2==1){
    sb=add(a,b);
    ml=mul(a,b);
    daodau(ml);
    if(cmp(a,b)>=0){
      ad=sub(a,b);
    }else{
      ad=sub(b,a);
      daodau(ad);
    }
  } else if(d1==1 &&d2==1){
    ad=add(a,b);
    daodau(ad);
    ml=mul(a,b);
    if(cmp(a,b)>=0){
      sb=sub(a,b);
      daodau(sb);
    }else{
      sb=sub(b,a);
    }
  }else{
    ml=mul(a,b);
    daodau(ml);
    sb=add(a,b);
    daodau(sb);
    if(cmp(a,b)>=0){
      ad=sub(a,b);
      daodau(ad);
    }else{
      ad=sub(b,a);
    }
  }
  print(ad);printf("\n");
  print(sb);printf("\n");
  print(ml);printf("\n");
}
