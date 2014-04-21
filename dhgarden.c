#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point_t;

#define CMP(a,b) ((a)>(b)?1:(a)<(b)?-1:0)

int cmp(const void *a,const void *b){
    point_t *A=(point_t*)a,
            *B=(point_t*)b;
    if(A->x!=B->x) return CMP(A->x,B->x);
    return CMP(A->y,B->y);
}

double cross(point_t* o,point_t *A,point_t *B){
    return (A->x-o->x)*(B->y-o->y)
        -(B->x-o->x)*(A->y-o->y);
}

void polygon(point_t *points,int n,point_t ** poly,int *size){
    register int i,usize=0,lsize=0,k=0;
    point_t *upper[20],*lower[20];
    for(i=0;i<n;++i){
        while(lsize>=2 && cross(lower[lsize-2],lower[lsize-1],points+i)<=0){
            --lsize;
        }
        lower[lsize++]=points+i;
    }
    for(i=n-1;i>=0;--i){
        while(usize>=2 &&cross(upper[usize-2],upper[usize-1],points+i)<=0){
            --usize;
        }
        upper[usize++]=points+i;
    }
    /*
    for(i=0;i<lsize;++i){
        printf("#1: %lf %lf\n",lower[i]->x,lower[i]->y);
    }
    for(i=0;i<usize;++i){
        printf("#2: %lf %lf\n",upper[i]->x,upper[i]->y);
    }
    */
    for(i=0;i<lsize-1;++i){
        poly[k++]=lower[i];
    }
    for(i=0;i<usize-1;++i){
        poly[k++]=upper[i];
    }
    /*
    for(i=0;i<k;++i){
        printf("#3 %lf %lf\n",poly[i]->x,poly[i]->y);
    }*/
    *size=k;
}
double distance(point_t *a,point_t *b){
    return sqrt((a->x-b->x)*(a->x-b->x)+
            (a->y-b->y)*(a->y-b->y));
}
long d;
int r,n;
point_t points[20];
int x[20],k;
int max;
void solve(){
    if(d<2*M_PI*r){
        max=0;
        return;
    }
    max=1;
    int i,j;
    point_t copy[20];
    point_t *poly[20];

    int psize;
    double len;
    for(k=2;k<=n;++k){
        for(i=0;i<k;++i) x[i]=i;
        for(;;){
            for(i=0;i<k;++i){
                copy[i]=points[x[i]];
            }
            polygon(copy,k,poly,&psize);
            
            /*
             *  tinh khoang cach
             */
            len=0;
            //printf("-----mmmmm------------\n");
            for(i=0;i<psize;i++){
                j=i+1;
                if(j>=psize) j=0;
                /*printf("%lf %lf  - %lf %lf\n",
                        poly[i]->x,poly[i]->y,
                        poly[j]->x,poly[j]->y);*/
                len+=distance(poly[j],poly[i]);
            }
            len+=2*M_PI*r;
            if(k>max && len<=d){
                max=k;
            }
            i=k-1;
            while(i>=0 && x[i]==n-k+i) i--;
            if(i<0) break;
            x[i]++;
            for(j=i+1;j<k;++j) x[j]=x[j-1]+1;
        }
    }
}
void read(){
    scanf("%ld%d%d",&d,&n,&r);
    int i;
    for(i=0;i<n;++i){
        scanf("%lf%lf",&(points[i].x),&(points[i].y));
    }
    qsort(points,n,sizeof(point_t),cmp);
    solve();
}
int main(){
    /*
    point_t ps[]={
        {0,0},{2,5},{4,0},{0,4},{1,1},{2,2},{4,4},{3,3},{5,2},{-2,-2}
    };
    int n=10;
    qsort(ps,n,sizeof(point_t),cmp);
    int i;
    point_t * poly[20];
    int psize;
    polygon(ps,n,poly,&psize);
    for(i=0;i<psize;++i){
        printf("#3 %lf %lf\n",poly[i]->x,poly[i]->y);
    }
    */
    int test;
    scanf("%d",&test);
    while(test--){
        read();
        printf("%d\n",max);
    }
    return 0;
}
