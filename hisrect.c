#include <stdio.h>
#include <stdlib.h>

int maxArea(int *hist,int n){
    int *ind=malloc(sizeof(int)*n);
    int *height=malloc(sizeof(int)*n);
    register int i,max=0,size=0,t,lastid;
    for(i=0;i<n;++i){
        if(size==0 || hist[i]>height[size-1]){
            ind[size]=i;
            height[size]=hist[i];
            ++size;
        }else if(hist[i]<height[size-1]){
            lastid=0;
            while(size>0 &&hist[i]<height[size-1]){
                lastid=ind[size-1];
                t=height[size-1]*(i-lastid);
                if(t>max) max=t;
                --size;
            }
            ind[size]=lastid;
            height[size]=hist[i];
            ++size;
        }
    }
    while(size){
        t=height[size-1]*(n-ind[size-1]);
        --size;
        if(t>max) max=t;
    }
    free(ind);
    free(height);
    return max;
}
int main(){
    int a[]={1,5,3,5,4,0};
    printf("%d",maxArea(a,6));
    return 0;
}
