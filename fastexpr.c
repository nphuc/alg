#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Abs(x) ((x)>0?(x):-(x))
typedef enum {
    NUM,
    ADD,
    SUB,
    MUL,
    ABS,
    OPB,
    CLB
} type;
typedef struct{
    type t;
    long d;
}elem;
typedef struct {
    int s;
    elem a[100];
} stack;

int isoperator(type t){
    return t==ADD ||t==SUB||t==MUL||t==ABS;
}
int isbrack(type t){
    return t==OPB||t==CLB;
}
int getPriority(type t){
    switch(t){
        case ADD:case SUB: return 1;break;
        case MUL: return 2;break;
        case NUM: return 0;break;
        case ABS: return 3;break;
        default: return -1;
    }
}
void prebuild(char *s,stack *res){
    int r=0;
    int i=0,n=strlen(s);
    long t;
    while(i<n){
        if(s[i]=='+'){
            if(i+1<n && isdigit(s[i+1])&& (r==0 || res->a[r-1].t==OPB)){
                t=0;
                ++i;
                while(i<n &&isdigit(s[i])){
                    t=t*10+s[i]-'0';
                    ++i;
                }
                res->a[r].d=-t;
                res->a[r++].t=NUM;
            }else{
                res->a[r++].t=ADD;
                i++;
            }
        }else if(s[i]=='-'){
            if(i+1<n && isdigit(s[i+1]) &&(r==0|| res->a[r-1].t==OPB)){
                t=0;
                ++i;
                while(i<n &&isdigit(s[i])){
                    t=t*10+s[i]-'0';
                    ++i;
                }
                res->a[r].d=-t;
                res->a[r++].t=NUM;
            }else{
                res->a[r++].t=SUB;
                i++;
            }
        }else if(s[i]=='*'){
            res->a[r++].t=MUL;
            i++;
        }else if(s[i]=='('){
            res->a[r++].t=OPB;
            i++;
        }else if(s[i]==')'){
            res->a[r++].t=CLB;
            i++;
        }else if(isdigit(s[i])){
            t=0;
            while(i<n && isdigit(s[i])){
                t=t*10+s[i]-'0';
                ++i;
            }
            res->a[r].t=NUM;
            res->a[r].d=t;
            ++r;
        }else if(isalpha(s[i])){
            res->a[r++].t=ABS;
            i+=3;
        }else{
            i++;
        }
    }
    res->s=r;
}
void postfix(stack *in,stack *out){
    stack st;
    st.s=0;
    int i=0,os=0;
    elem x;
    for(i=0;i<in->s;++i){
        if(in->a[i].t==NUM){
            out->a[os++]=in->a[i];
        }else if(in->a[i].t==OPB){
            st.a[st.s++]=in->a[i];
        }else if(in->a[i].t==CLB){
            x=st.a[--st.s];
            while( x.t!=OPB){
                out->a[os++]=x;
                x=st.a[--st.s];
            }
        }else{
            while(st.s>0 && getPriority(in->a[i].t)<=
                    getPriority(st.a[st.s-1].t)){
                out->a[os++]=st.a[--st.s];
            }
            st.a[st.s++]=in->a[i];
        }
    }
    while(st.s){
        out->a[os++]=st.a[--st.s];
    }
    out->s=os;
}

long compute(stack *pf){
    stack st;
    st.s=0;
    int i,j;
    for(i=0;i<pf->s;++i){
        /*puts("WATCH-----------");
          for(j=0;j<st.s;++j){
          switch(st.a[j].t){
          case ADD: puts("+");break;
          case SUB: puts("-");break;
          case MUL: puts("*");break;
          case ABS: puts("abs");break;
          case NUM: printf("%ld\n",st.a[j].d);break;
          }
          }*/
        if(pf->a[i].t==NUM){
            st.a[st.s++]=pf->a[i];
        }else if(pf->a[i].t==ABS){
            st.a[st.s-1].d=Abs(st.a[st.s-1].d);
        }else{
            long x=st.a[--st.s].d;
            long y=st.a[--st.s].d;
            switch(pf->a[i].t){
                case ADD: y+=x; break;
                case SUB: y-=x; break;
                case MUL: y*=x; break;
            }
            //printf("OPR= %d\n",pf->a[i].t);
            //printf("y=%ld\n",y);
            st.a[st.s++].d=y;
        }
    }
    return st.a[st.s-1].d;
}
void printstack(stack *out){
    int i;
    for(i=0;i<out->s;++i){
        switch(out->a[i].t){
            case ADD: puts("+");break;
            case SUB: puts("-");break;
            case MUL: puts("*");break;
            case OPB: puts("(");break;
            case CLB: puts(")");break;
            case ABS: puts("abs");break;
            case NUM: printf("%ld\n",out->a[i].d);break;
        }
    }
}
long solve(stack *in){
    int i=0;
    stack t;
    stack no,pf;
    no.s=0;
    //puts("#############");
    //printstack(in);
    while(i<in->s){
        if(in->a[i].t==ABS){
            ++i;
            t.s=0;
            int lv=1;
            for(;;){
                //printf("%d\n",i);
                t.a[t.s++]=in->a[i];
                if(in->a[i].t==OPB){
                    ++lv;
                }else if(in->a[i].t==CLB){
                    --lv;
                }
                ++i;
                if(lv==1) break;
            }
            //puts("reach??");
            long res=Abs(solve(&t));
            no.a[no.s].d=res;
            no.a[no.s].t=NUM;
            ++no.s;
        }else{
            no.a[no.s++]=in->a[i];
            ++i;
        }
    }
    //puts("NO abs");
    //printstack(&no);
    postfix(&no,&pf);
    return compute(&pf);
}
int main(){
    char s[1000];
    register int i=0;
    int c;
    while((c=getchar_unlocked())!=EOF){
    	if(!isspace(c)){
    		s[i++]=c;
    	}
    }
    s[i]=0;
    stack st;
    prebuild(s,&st);
    stack out;
    //postfix(&st,&out);
    //long res=compute(&out);
    //printf("res1=%ld\n",res);
    long res2=solve(&st);
    printf("%ld",res2);
    return 0;
}

