#include <stdio.h>
#include <stdlib.h>

typedef struct bnode{
  int key;
  int value;
  struct bnode *left,*right;
}bnode;
typedef struct btree{
  bnode * root;
}btree;

void bnode_print(bnode* node,char *s){
  printf("#bnode(%s) {key:%d, value:%d, left:%p,right%p}\n",
      s,node->key,node->value,node->left,node->right);
}

bnode* bnode_new(int key,int value){
  bnode * res=(bnode*)malloc(sizeof(bnode));
  res->key=key;
  res->value=value;
  res->left=NULL;
  res->right=NULL;
  return res;
}
bnode* btree_insert(btree* tree,int key,int value){
  bnode* res=bnode_new(key,value);
  bnode *curr=tree->root;
  if(!tree->root) {
    tree->root=res;
    goto _end;
  }
  for(;;){
    //bnode_print(curr,"curr");
    if(key>curr->key){
      if(curr->right){
        curr=curr->right;
      }else{
        curr->right=res;
        goto _end;
      }
    }else if (key<curr->key){
      if(curr->left){
        curr=curr->left;
      }else{
        curr->left=res;
        goto _end;
      }
    }else break;
  }
_end: return res;
}

bnode *btree_min(btree* tree){
  bnode *min=tree->root;
  if(!min){ return NULL;}
  while(min->left) min=min->left;
  return min;
}
bnode *btree_max(btree* tree){
  bnode *max=tree->root;
  if(!max){ return NULL;}
  while(max->right) max=max->right;
  return max;
}
int main(){
  btree tree;
  tree.root=NULL;
  btree_insert(&tree,1,12);
  btree_insert(&tree,4,234);
  btree_insert(&tree,0,23);
  btree_insert(&tree,2,26);
  bnode *max=btree_max(&tree);
  bnode_print(max,"max");  
}
