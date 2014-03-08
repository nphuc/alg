#include <stdio.h>
#include <stdlib.h>

typedef struct p{
  long x,y,i;
}p;
#define ADD(a,b,c) do{(a).x=(b).x+(c).x;(a).y=(b).y+(c).y;}while(0)
#define SUB(a,b,c) do{(a).x=(b).x-(c).x;(a).y=(b).y-(c).y;}while(0)
#define ABS(x) ((x)>0?(x):-(x))
int cmpv(const void *a,const void *b){
  p *t1=(p*)a;
  p *t2=(p*)b;
  return ABS(t1->x)+ABS(t1->y)-ABS(t2->x)-ABS(t2->y);
}
int cmpi(const void *a,const void *b){
  p *t1=(p*)a;
  p *t2=(p*)b;
  return t1->i-t2->i;
}
#define maxN 10100
p pt[maxN];
long n,l;
int t[maxN];
int main(){
  scanf("%ld%ld",&n,&l);
  long i;
  for(i=0;i<n;++i){
    scanf("%ld%ld",&(pt[i].x),&(pt[i].y));
  }
}
