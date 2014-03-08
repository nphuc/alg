#include <stdio.h>
#include <stdlib.h>
#define maxN 5100
typedef long long ll;
typedef struct point{
  long x,y;
}point;
long n;
point p[maxN];
int cmp(const void *a,const void *b){
  point *u=(point*)a,
        *v=(point*)b;
  return (u->y > v->y?1:u->y < v->y?-1:0);
}
point p1[maxN/2],p2[maxN/2];
long n1,n2;
point pMax={.x=0,.y=-999999},pMin={.x=0,.y=999999};
long search(const point *p1,long n1,const point *pt){
  long st=0,nd=n1;
  if(cmp(pt,&pMin)<0) return -1;
  if(cmp(pt,&pMax)>0) return -1;
  do{
    long mid=(st+nd)/2;
    if(cmp(p1+mid,pt)>0) st=mid;
    else nd=mid;
  }while(st+1!=nd);
  return st;
}
int inside(point *pt){
  long i1=search(p1,n1,pt),
       i2=search(p2,n2,pt);

}
int main(){
  scanf("%ld",&n);
  long i;
  for(i=0;i<n;++i){
    scanf("%ld%ld",&(p+i)->x,&(p+i)->y);
    if(cmp(p+i,&pMax)>0) pMax=p[i];
    if(cmp(p+i,&pMin)<0) pMin=p[i];
  }
  int change=1;
  n1=0;n2=0;
  for(i=0;i<n;++i){
    if(cmp(p+i,&pMax)==0) change=0;
    if(cmp(p+i,&pMin)==0) change=1;
    if(change) {
      p1[n1]=p[i];
      ++n1;
    }else{
      p2[n2]=p[i];
      ++n2;
    }
  }
  qsort(p1,n1,sizeof(point),cmp);
  qsort(p2,n2,sizeof(point),cmp);
  long q;
  scanf("%ld",&q);
  point pq;
  for(i=0;i<q;++i){
    scanf("%ld%ld",&pq.x,&pq.y);
    printf("%ld %ld\n",search(p1,n1,&pq),search(p2,n2,&pq));
  }
  return 0;
}
