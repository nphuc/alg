#include <stdio.h>
#include <stdlib.h>

#define M 210
int x[M],a[M][M],s,n,k,
    ok=0,su=0;
int getInt(){
    int res=0;
    char c;
    for(;;){
        c=getchar_unlocked();
        if(isdigit(c)) break;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res;
}
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
void p(int *a,int n){
    int i;
    for(i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int search(int *arr,int v){
    int st=0,nd=n+1,m;
    do{
        m=(st+nd)/2;
        if(arr[m]>v){
            nd=m;
        }else{
            st=m;
        }       
    }while(st+1!=nd);
    return st;
}
void Try(int i){
    if(!ok){
        if(i==k){
            if(su==s){
                printf("YES\n");
                p(x,k);
                ok=1;
                return;
            }
        }else{
            int j;
            int tb=(s-su)/(k-i);
            for(j=0;j<n;++j){
                if(((i==0)||(i>0)&&(a[j][i]>=x[i-1]))
                        &&(a[j][i]<=tb)){
                    su+=a[j][i];
                    x[i]=a[j][i];
                    Try(i+1);
                    su-=a[j][i];
                }
            }
        }
    }
}

int main(){
    int i,j;
    s=getInt(),k=getInt(),n=getInt();
    for(j=0;j<n;++j){
        for(i=0;i<k;++i){
            a[j][i]=getInt();
        }
    }
    Try(0);
    if(!ok){
        printf("NO");
    }
    return 0;
}

