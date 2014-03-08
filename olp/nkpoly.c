#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define f_i ""
#define f_o ""
typedef long long ll;
typedef struct vt{
  float x,y;
}vt;
#define GAN(a,b) do{(a).x=(b).x; (a).y=(b).y;}while(0)
#define GANXY(a,m,n) do{(a).x=m;(a).y=n;}while(0)
#define SUB(c,a,b) GANXY(c,(a).x-(b).x,(a).y-(b).y)
#define ADD(c,a,b) GANXY(c,(a).x+(b).x,(a).y+(b).y)
#define TICHCH(a,b) ((a).x*(b).y-(a).y*(b).x)
#define TICHVH(a,b) ((a).x*(b).x-(a).y*(b).y)
#define D(a,b) sqrt((a).x*(a).x+(b).y*(b).y)
#define ABS(x) ((x)>0?(x):-(x))
#define maxN 210
vt p[maxN];
int n;
float mn[maxN],mx[maxN];
void solve(int i){
  int a=i+1,b=i+2;
  int c;
  vt cb,ca;
  float s,mins=FLT_MAX,maxs=FLT_MIN;
  for(c=0;c<n-2;++c){
    if(a>=n) a=0;
    b=a+1;
    if(b>=n) b=0;
    SUB(cb,*(p+b),*(p+i));
    SUB(ca,*(p+a),*(p+i));
    s=ABS(TICHCH(cb,ca))/2;
    //printf("%f\n",s);
    //printf("%f,%f  %f,%f %f,%f\n",(p+i)->x,(p+i)->y,(p+a)->x,(p+a)->y,(p+b)->x,(p+b)->y);
    if(s<mins) mins=s;
    if(s>maxs) maxs=s;
    ++a;
  }
  mx[i]=maxs;
  mn[i]=mins;
}
float Max(){
  float r=FLT_MIN;
  int i;
  for(i=0;i<n;++i) if( mx[i]>r) r=mx[i];
  return r;
}
float Min(){
  float r=FLT_MAX;
  int i;
  for(i=0;i<n;++i) if( mx[i]<r) r=mx[i];
  return r;
}
int main(){
  scanf("%d",&n);
  int i;
  for(i=0;i<n;++i){
    scanf("%f%f",&(p+i)->x,&(p+i)->y);
  }
  for(i=0;i<n;++i){
    solve(i);
  }
  printf("%.1f\n%.1f\n",Max(),Min());
  return 0;
}
