#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

typedef struct point{
  int x,y;
  point(){}
  point(int x,int y):x(x),y(y){

  }
  bool operator<(const point &o) const{
    if(y!=o.y) return y<o.y;
    return x<o.x;
  }
  void p()const {
    printf("point {%d,%d}\n",x,y);
  }
}point;

typedef map<point,int> Path;
typedef Path::iterator PI;

int main(){
  point a(1,2);
  point b(2,3);
  Path p;
  p[a]=1;
  p[b]=2;
  PI pi;
  for(pi=p.begin();pi!=p.end();++pi){
    pi->first.p();
    printf("%d\n",pi->second);
  }
}
