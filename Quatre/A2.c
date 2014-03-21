#include<stdio.h>
#include"tree.h"
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d",arg->value);
}
unsigned char comp(const node_t*node,void*target)
{
	return node==target;
}
int main()
{
	node_t*tree=0;
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
	{
		node_t*a=bst_search(&tree,3);
		node_t*b=bst_search(&tree,6);
		unsigned char route= node_linked_any(a,comp,b);
		fprintf(stdout,"%d -> %d : %s\n",a->value,b->value,route?"connected":"not connected");
	}
	return 0;
}
