#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define f_i "LEM.INP"
#define f_o ""

#define max 1002
typedef long long ll;
float d[max*max];
typedef struct point{
  int x,y;
}point;

ll tich1(point *p1,point *p2){
  return p1->x*p2->x+p1->y*p2->y;
}
point sub(point *a,point *b){
  point p;
  p.x=a->x-b->x;
  p.y=a->y-b->y;
  return p;
}
#define D0(a,b) sqrt((a)*(a)+(b)*(b))
#define D(a,b) D0(a.x-b.x,a.y-b.y)
float min(point *a,point *b,point *c){
  point ba=sub(a,b);
  point ca=sub(a,c);
  point bc=sub(c,b);
  point cb=sub(b,c);
  //printf("%ld %ld %ld %ld %ld %ld\n",a->x,a->y,b->x,b->y,c->x,c->y);
  float s;
  if(tich1(&ba,&bc)<=0){
    //printf("#case 1\n");
    return D0(ba.x,ba.y);
  }else if(tich1(&ca,&cb)<=0){
    //printf("#case 2\n");
    return D0(ca.x,ca.y);
  }else{
    s=abs(ba.x*ca.y-ba.y*ca.x);
    //printf("#case 3\n");
    return s/D0(bc.x,bc.y);
  }
}
int main(){
  float mn=10000000,d;
  int i,n,m,j;
  //FILE *fi=fopen(f_i,"r");
  FILE *fi=stdin;
  point u[max],v[max];
  point *prev;
  fscanf(fi,"%d%d",&n,&m);
  for(i=0;i<n;++i) fscanf(fi,"%d%d",&(u[i].x),&(u[i].y));
  for(i=0;i<m;++i) fscanf(fi,"%d%d",&(v[i].x),&(v[i].y));
  for(i=0;i<n;++i){
    prev=v;
    for(j=1;j<m;++j){
      d=min(u+i,prev,v+j);
      //printf("%f\n",d);
      if(d<mn) mn=d;
      prev=v+j;
    }
  }
  /*for(j=0;j<m;++j){
    prev=u;
    for(i=1;i<n;++i){
      d=min(v+j,prev,u+i);
      if(d<mn) mn=d;
    }
    prev=u+i;
  }*/
  printf("%.3f",mn);
  return 0;
}
