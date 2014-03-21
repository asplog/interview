#include<stdio.h>
#include"tree.h"
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d",arg->value);
}
int max(int a,int b)
{
	return a<b?b:a;
}
int abs(int v)
{
	return v<0?-v:v;
}
int node_get_balanced_height(const node_t*node,int depth)
{
	if(node)
	{
		int l=node_get_balanced_height(node->gauche,depth+1);
		int r=node_get_balanced_height(node->droite,depth+1);
		depth=0<l&&0<r&&abs(l-r)<2?max(l,r):-1;
#ifdef __DEBUG__
		fprintf(stderr,"%d(%d) %d %d(%d) is %d\n",node->gauche?node->gauche->value:-1,l,node->value,node->droite?node->droite->value:-1,r,depth);	
#endif
	}
	return	depth;	
}
int main()
{
	int depth;
	node_t*tree=0;
	if(1)
	{
		bst_add(&tree,3);
		bst_add(&tree,1);
		bst_add(&tree,4);
		bst_add(&tree,1);
		bst_add(&tree,5);
		bst_add(&tree,9);
		bst_add(&tree,2);
		bst_add(&tree,6);
	}
	else
	{
		bst_add(&tree,4);
		bst_add(&tree,2);
		bst_add(&tree,6);
		bst_add(&tree,1);
		bst_add(&tree,3);
		bst_add(&tree,5);
	}
	depth=node_get_balanced_height(tree,0);
	fprintf(stdout,"Tree is %s\n",0<depth?"balanced":"not balanced");
	return 0;
}
