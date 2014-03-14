function Bnode(key,value){
  this.key=key;
  this.value=value;
  this.left=null;
  this.right=null;
}
function Btree(){
  this.root=null;
}
Btree.prototype={
  insert:function(key,value){
    var node=new Bnode(key,value);
    if(!this.root){
      this.root=node;
    }else{
      var curr=this.root;
      for(;;){
        if(curr.key==key) break;
        else if(curr.key<key){
          if(!curr.right){
            curr.right=node;
          }else{
            curr=curr.right;
          }
        }else{
          if(!curr.left){
            curr.left=node;
          }else{
            curr=curr.left;
          }
        }
      }
    }
    return node;
  }
}

module.exports={
  Bnode:Bnode,
  Btree:Btree
};
