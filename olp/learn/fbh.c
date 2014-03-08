//FIBONACCI HEAP AND OPERATIONS ON IT//

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>

typedef long data;
typedef struct node
{
  long n;
  long degree;
  struct node *parent,*child,*left,*right;
  char mark;
  char C;
}node ;

int nH;
node* MAKE_FIB_HEAP();
int FIB_HEAP_LINK(node*,node*,node*);
node* CREATE_NODE(long);
node* FIB_HEAP_INSERT(node*,node*);
node* FIB_HEAP_UNION(node*,node*);
node* FIB_HEAP_EXTRACT_MIN(node*);
int CONSOLIDATE(node*);
int DISPLAY(node*);
int DISPLAY_1(node*);
node* H=NULL;
node* FIND_NODE(node*,long);
int FIB_HEAP_DECREASE_KEY(node*,long,long);
int FIB_HEAP_DELETE_KEY(node*,long);
int CUT(node*,node*,node*);
int CASCADE_CUT(node*,node*);
int PRESENT_NODE(node*);

int main()
{
  srand(time(NULL));
  long i,t,m=10;
  node *n;
  for(i=0;i<m;++i){
    t=rand()%m+1;
    n=CREATE_NODE(t);
    H=FIB_HEAP_INSERT(H,n);
    //printf("%4ld",t);
  }
  //printf("\n");
  DISPLAY(H);
  while(H!=NULL){
    printf("%ld\n",H->n);
    FIB_HEAP_EXTRACT_MIN(H);
  }
}
node* MAKE_FIB_HEAP()
{
  node* np=(node*)malloc(sizeof(node));
  np=NULL;
  return np;
}
node* CREATE_NODE(long k)
{
  node* x=(node*)malloc(sizeof(node));
  x->n=k;
  x->parent=NULL;
  x->child=NULL;
  x->left=x->right=x;
  return x;
}
node* FIB_HEAP_INSERT(node* H,node* x)
{
  x->degree=0;
  x->parent=NULL;
  x->child=NULL;
  x->left=x;
  x->right=x;
  x->mark='F';
  x->C='N';
  if(H!=NULL)
  {
    (H->left)->right=x;
    x->right=H;
    x->left=H->left;
    H->left=x;
    if(x->n<H->n)
      H=x;
  }
  else
  {
    H=x;
  }
  nH=nH+1; 
  return H;
}

int FIB_HEAP_LINK(node* H1,node* y,node* z)
{
  (y->left)->right=y->right;
  (y->right)->left=y->left;
  if(z->right==z)
    H1=z;
  y->left=y;
  y->right=y;
  y->parent=z;
  if(z->child==NULL)
    z->child=y;
  y->right=z->child;
  y->left=(z->child)->left;
  ((z->child)->left)->right=y;
  (z->child)->left=y;
  if(y->n<(z->child)->n)
    z->child=y;
  z->degree++;
}

node* FIB_HEAP_UNION(node* H1,node* H2)
{
  node* np;
  node* H=MAKE_FIB_HEAP();
  H=H1;
  (H->left)->right=H2;
  (H2->left)->right=H;
  np=H->left;
  H->left=H2->left;
  H2->left=np;
  return H;
}

int DISPLAY(node* H)
{
  node* p=H;
  if(p==NULL)
  {
    printf("\nHEAP EMPTY!!!\n");
    return 0;
  }
  printf("\nTHE ROOT NODES OF THE HEAP ARE:\n");
  do{
    printf("%ld",p->n);
    p=p->right;
    if(p!=H)
    { printf("-->");}
  }while(p!=H);
  printf("\n");
}

node* FIB_HEAP_EXTRACT_MIN(node* H1)
{
  node* p;node* ptr;
  node* z=H1;
  p=z;
  ptr=z;
  if(z==NULL)
    return z;
  node* x;
  node* np;
  x=NULL;
  if(z->child!=NULL)
    x=z->child;
  if(x!=NULL)
  {
    ptr=x;
    do
    {
      np=x->right;
      (H1->left)->right=x;
      x->right=H1;
      x->left=H1->left;
      H1->left=x;
      if(x->n<H1->n)
        H1=x;
      x->parent=NULL;
      x=np;
      //np=np->right;
    }while(np!=ptr);
  }  
  (z->left)->right=z->right;
  (z->right)->left=z->left;
  H1=z->right;
  if(z==z->right&&z->child==NULL)
  {
    H=NULL;
  }

  else
  {
    H1=z->right;
    CONSOLIDATE(H1);
  }
  nH=nH-1;
  return p;
}
int CONSOLIDATE(node* H1)
{
  int d;
  float f=(log(nH))/(log(2));
  int D=f;
  node* A[D];
  long i;
  for(i=0;i<=D;i++)
    A[i]=NULL;
  node* x=H1;
  node* y;
  node* np;
  node* pt=x;
  do
  {
    pt=pt->right;
    d=x->degree;
    while(A[d]!=NULL)
    {
      y=A[d];
      if(x->n>y->n)
      {
        np=x;
        x=y;
        y=np;

      }
      if(y==H1)
        H1=x;
      FIB_HEAP_LINK(H1,y,x);  
      if(x->right==x)
        H1=x;
      // DISPLAY(H1);
      A[d]=NULL;
      d=d+1;
    }

    A[d]=x;
    x=x->right;
  }while(x!=H1);
  H=NULL;
  long j;
  for(j=0;j<=D;j++)
  {
    if(A[j]!=NULL)
    {
      A[j]->left=A[j];
      A[j]->right=A[j];
      if(H!=NULL)
      {
        (H->left)->right=A[j];
        A[j]->right=H;
        A[j]->left=H->left;
        H->left=A[j];
        if(A[j]->n<H->n)
          H=A[j];
      }
      else
      {
        H=A[j];
      }
      if(H==NULL)
        H=A[j];
      else if(A[j]->n<H->n)
        H=A[j];
    }
  }
}

int DISPLAY_1(node* H)
{
  printf("\nthrough display 1");
  node* p=H;
  if(p==NULL)
  {
    printf("\nHEAP EMPTY!!!\n");
    return 0;
  }
  printf("\nTHE ROOT NODES OF THE HEAP ARE:\n");
  do{
    printf("%ld",p->n);
    if(p->child!=NULL)printf("child=%ld",(p->child)->n);else printf("child=0");
    p=p->left;


    if(p!=H)
    {printf("-->");}
  }while(p!=H);
  printf("\n");
}
int FIB_HEAP_DECREASE_KEY(node*H1,long x,long k)
{
  node* y;
  if(H1==NULL)
  {
    printf("\nNO NODE IN THE HEAP!!! ABORTING!!!!");
    return 0;
  }
  node* ptr=FIND_NODE(H1,x);
  if(ptr==NULL)
  {
    printf("\nTHE TARGET NODE NOT FOUND!!!!!");
    return 1;
  }
  // cout<<"\nptr="<<ptr->n;
  if(ptr->n<k)
  {
    printf("\nTHE ENTERED KEY IS GREATER THAN THE CURRENT VALUE!!!");
    return 0;
  }
  ptr->n=k;
  y=ptr->parent;
  if(y!=NULL&&ptr->n<y->n)
  {
    CUT(H1,ptr,y);
    CASCADE_CUT(H1,y);
  }
  if(ptr->n<H->n)
    H=ptr;//cout<<"\nH="<<ptr->n;}
    return 0;
    }

int CUT(node* H1,node* x,node* y)
{
  if(x==x->right)
    y->child=NULL;
  (x->left)->right=x->right;
  (x->right)->left=x->left;
  if(x==y->child)
    y->child=x->right;
  y->degree=y->degree-1;
  x->right=x;
  x->left=x;
  (H1->left)->right=x;
  x->right=H1;
  x->left=H1->left;
  H1->left=x;
  x->parent=NULL;
  x->mark='F';
}


int CASCADE_CUT(node* H1,node* y)
{
  node* z=y->parent;
  if(z!=NULL)
  {
    if(y->mark=='F')
    {
      y->mark='T';
    }
    else
    {
      CUT(H1,y,z);
      CASCADE_CUT(H1,z);
    }

  }
}
node* FIND_NODE(node* H,long k)
{
  node* x=H;
  x->C='Y';
  node* p=NULL;
  if(x->n==k)
  {
    p=x;
    x->C='N';
    return p;
  }
  if(x->child!=NULL&&p==NULL)
  {
    p=FIND_NODE(x->child,k);
  }
  if((x->right)->C!='Y'&&p==NULL)
  {
    p=FIND_NODE(x->right,k);
  }
  x->C='N';  
  return p; 
}

int FIB_HEAP_DELETE_KEY(node* H1,long k)
{
  node* np=NULL;
  int t;
  t=FIB_HEAP_DECREASE_KEY(H1,k,-5000);
  //cout<<"\nin deletion before extracting H="<<H->n;
  if(!t)
    np=FIB_HEAP_EXTRACT_MIN(H);
  if(np!=NULL)
    printf("\nTHE KEY DELETED SUCCESSFULLY!!");
  else 
    printf("\nA PROBLEM OCCURED DURIING DELETION!!!");
  return 0;
}

int PRESENT_NODE(node* H)
{
  node* x=H;
  printf("(%ld)",x->n);
  x->C='Y';
  if(x->child!=NULL)
  {
    PRESENT_NODE(x->child);
  }
  if((x->right)->C!='Y')
  {
    PRESENT_NODE(x->right);
  }
  x->C='N';  
}
