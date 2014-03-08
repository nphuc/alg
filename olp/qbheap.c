#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
#define maxN 15100
#define f_i "QBHEAP.INP"

long a[maxN],n=0,res[maxN];
FILE *fi;
int cmp(const void *a,const void *b){
  long d=*(long*)a-*(long*)b;
  return d>0?1:d<0?-1:0;
}
void insert(long v){
  if(n>=15000) return;
  a[n]=v;
  ++n;
}
void deleteMax(){
  qsort(a,n,sizeof(long),cmp);
  long last=n-1;
  while(n>=0 && a[n-1]==a[last]){
    --n;
  }
}
int main(){
  fi=fopen(f_i,"r");
  //fi=stdin;
  char *s=malloc(25);
  size_t buff;
  long v;
  while(getline(&s,&buff,fi)!=EOF){
    if(s[0]=='+'){
      sscanf(s+1,"%ld",&v);
      insert(v);
    }else{
      deleteMax();
    }
  }
  long i;
  long size=0;
  for(i=n-1;i>=0;--i){
    if(!size || res[size-1] != a[i]){
      res[size]=a[i];
      ++size;
    }
  }
  printf("%ld\n",size);
  for(i=0;i<size;++i){
    printf("%ld\n",res[i]);
  }
  free(s);
  return 0;
}
