#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* simple kd tree */
#define DIM 2
typedef struct node_t{
	double x[DIM];
	struct node_t *left,*right;
}node;

inline double dist(node *a,node *b){
	double t,d=0;
	int dim=DIM;
	while(dim--){
		t=a->x[dim]-b->x[dim];
		d+=t*t;
	}
	return d;
}
inline void swap(node *a,node *b){
	double tmp[DIM];
	memcpy(tmp,a->x,sizeof(tmp));
	memcpy(a->x,b->x,sizeof(tmp));
	memcpy(b->x,tmp,sizeof(tmp));
}

inline node* findmedian(node *start,node *end,int idx){
	if(end<start) return NULL;
	if(start+1==end) return start;
	node *p,*store,*md=start+(end-start)/2;
	double pivot;
	while(1){
		pivot=md->x[idx];
		swap(md,end-1);
		for (store = p = start; p < end; p++) {
			if (p->x[idx] < pivot) {
				if (p != store)
					swap(p, store);
				store++;
			}
		}
		swap(store, end - 1);
		if (store->x[idx] == md->x[idx])
			return md;
 
		if (store > md)	end = store;
		else		start = store;
	}
}
node *maketree(node* t,int len,int i){
	node *n;
	if(!len) return NULL;
	if((n=findmedian(t,t+len,i))){
		i=(i+1)%DIM;
		n->left  = maketree(t, n - t, i);
		n->right = maketree(n + 1, t + len - (n + 1), i);
	}
	return n;
}
void nearest(node *root, node *nd, int i, node**best, double *best_dist){
	double d, dx, dx2;
	if (!root) return;
	d = dist(root, nd);
	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;
	if (!*best || d < *best_dist) {
		*best_dist = d;
		*best = root;
	}
 
	if (!*best_dist) return;
 
	if (++i >= DIM) i = 0;
 
	nearest(dx > 0 ? root->left : root->right, nd, i, best, best_dist);
	if (dx2 >= *best_dist) return;
	nearest(dx > 0 ? root->right : root->left, nd, i, best, best_dist);
}
void p(node *n){
	if(n){
		printf("node: %lf, %lf\n",n->x[0],n->x[1]);
		p(n->left);
		p(n->right);
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	node wp[n+2], *root,*found;
	double best_dist=1000000;
	for(i=0;i<n;++i){
		scanf("%lf%lf",wp[i].x,wp[i].x+1);
	}
	root=maketree(wp,n,0);
	//p(root);
	node t={{2,3}};
	nearest(root,&t,0,&found,&best_dist);
	printf("%lf\n",best_dist);
	return 0;
}
