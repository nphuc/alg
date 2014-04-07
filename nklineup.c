#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define minVal(a,b) ((a)<(b)?(a):(b))
#define maxVal(a,b) ((a)>(b)?(a):(b))
#define getMid(s,e) ((s)+((e)-(s))/2)

long RMQUtil(long *st,long ss,long se,long qs,long qe,long index){
    if(qs<=ss && qe>=se){
        return st[index];
    }
    if(se<qs || ss>qe){
        return LONG_MAX;
    }
    long mid=getMid(ss,se);
    long a=
            RMQUtil(st,ss,mid,qs,qe,2*index+1),
            b=RMQUtil(st,mid+1,se,qs,qe,2*index+2);
    return minVal(a,b);
}
long RMQ(long *st,long n,long qs,long qe){
    return RMQUtil(st,0,n-1,qs,qe,0);
}
long constructSTUtil(long *arr,long ss,long se,long *st,long si){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }
    long mid=getMid(ss,se);
    long a=constructSTUtil(arr,ss,mid,st,si*2+1),
            b=constructSTUtil(arr,mid+1,se,st,si*2+2);
    st[si]=minVal(a,b);
    return st[si];
}
long *constructST(long *arr,long n){
    long x=(long)ceil(log2(n));
    long max_size=2*(int)pow(2,x)-1;
    long *st=malloc(sizeof(long)*max_size);
    constructSTUtil(arr,0,n-1,st,0);
    return st;
}
long RMQUtil2(long *st,long ss,long se,long qs,long qe,long index){
    if(qs<=ss && qe>=se){
        return st[index];
    }
    if(se<qs || ss>qe){
        return LONG_MIN;
    }
    long mid=getMid(ss,se);
    long a=
            RMQUtil2(st,ss,mid,qs,qe,2*index+1),
            b=RMQUtil2(st,mid+1,se,qs,qe,2*index+2);
    return maxVal(a,b);
}
long RMQ2(long *st,long n,long qs,long qe){
    return RMQUtil2(st,0,n-1,qs,qe,0);
}
long constructSTUtil2(long *arr,long ss,long se,long *st,long si){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }
    long mid=getMid(ss,se);
    long a=constructSTUtil2(arr,ss,mid,st,si*2+1),
            b=constructSTUtil2(arr,mid+1,se,st,si*2+2);
    st[si]=maxVal(a,b);
    return st[si];
}
long *constructST2(long *arr,long n){
    long x=(long)ceil(log2(n));
    long max_size=2*(int)pow(2,x)-1;
    long *st=malloc(sizeof(long)*max_size);
    constructSTUtil2(arr,0,n-1,st,0);
    return st;
}

long getLong(){
    long res=0;
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

int main(){
    long n,q;
    long *arr;   
    n=getLong();
    q=getLong();
    arr=malloc(sizeof(long)*(n+1));
    register long i;
    for(i=0;i<n;++i){
        arr[i]=getLong();
    }
    long *stmin=constructST(arr,n);
    long *stmax=constructST2(arr,n);
    i=q;
    long a,b;
    while(i--){
        a=getLong();
        b=getLong();
        printf("%ld\n",RMQ2(stmax,n,a-1,b-1)-RMQ(stmin,n,a-1,b-1));
    }
    free(arr);
    free(stmin);
    free(stmax);
    return 0;
}
