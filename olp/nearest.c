#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <inttypes.h>
#include <float.h>
#define f_i ""
#define f_o ""
#define SQR(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):-(x))
#define D(a,b) sqrt(SQR((a).x-(b).x)+SQR((a).y-(b).y))
typedef struct vector{
  float x,y;
}vector;
#define max 100100
vector v[max];
long n;
int main(){
  long i,j;
  scanf("%ld",&n);
  float d,min=FLT_MAX;
  printf("%.3f",min);
  return 0;
}
