#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;


#define f_i "VOSNET.INP"
#define f_o "VOSNET.OUT"
FILE *fi,*fo;

#define ABS(x) ((x)<0?-(x):(x))
typedef struct con{
  int a,b;
  con(){}
  con(int aa,int bb){
    if(aa<bb){
      a=aa;
      b=bb;
    }else{
      a=bb;
      b=aa;
    }
  }
  bool operator==(const con&o) const{
    return a==o.a &&b==o.b;
  }
  bool operator!=(const con&o) const{
    return (a!=o.a|| b!=o.b);
  } 
  bool operator<(const con&o) const{
    if(a!=o.a) return a<o.a;
    return b<o.b;
  }
  bool operator>(const con&o) const{
    if(a!=o.a) return a>o.a;
    return b>o.b;
  }
  void p() const{
    printf("con {%d,%d}\n",a,b);
  }
} con;

typedef map<con,int> net;
typedef net::iterator NI;
int m,n;
net g;
void readfile(){
  //fi=fopen(f_i,"r");
  fi=stdin;
  fscanf(fi,"%d%d",&n,&m);
  int i;
  con t;
  for(i=0;i<m;++i){
    fscanf(fi,"%d%d",&(t.a),&(t.b));
    g[t]=1;
  }
  fclose(fi);
}
unsigned long next(){
  NI ia,ib;
  con t;
  con nia,nib;
  net newn;
  for(ia=g.begin();ia!=g.end();++ia){
    for(ib=NI(ia);ib!=g.end();++ib){
      nia=ia->first;
      nib=ib->first;
      if(nia!=nib){
        if(nia.a==nib.a){
          t=con(nia.b,nib.b);
          if(g.find(t)==g.end()&& t.a!=t.b){
             //printf("%d %d - %d %d\n",nia.a,nia.b,nib.a,nib.b);
            if(newn.find(t)==newn.end())newn[t]=1;
          }
        }else if(nia.a==nib.b){
          t=con(nia.b,nib.a);
          if(g.find(t)==g.end()&& t.a!=t.b){
             //printf("%d %d - %d %d\n",nia.a,nia.b,nib.a,nib.b);
            if(newn.find(t)==newn.end())newn[t]=1;
          }
        }else if(nia.b==nib.a){
          t=con(nia.a,nib.b);
          if(g.find(t)==g.end()&& t.a!=t.b){
             //printf("%d %d - %d %d\n",nia.a,nia.b,nib.a,nib.b);
            if(newn.find(t)==newn.end())newn[t]=1;
          }
        }else if(nia.b==nib.b){
          t=con(nia.a,nib.a);
          if(g.find(t)==g.end()&& t.a!=t.b){
            //printf("%d %d - %d %d\n",nia.a,nia.b,nib.a,nib.b);
            if(newn.find(t)==newn.end())newn[t]=1;
          }
        }
      }
    }
  }
  for(ia=newn.begin();ia!=newn.end();++ia) {
    g[ia->first]=1;  
  }
  return newn.size();
}
int main(){
  readfile();
  long c;
  for(;;){
    c=next();
    if(c!=0){
      printf("%lu ",c);
    }else{
      printf("%lu",c);
      break;
    }
  }
}
