#include<stdio.h>
#include"tree.h"
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d",arg->value);
}
node_t*search_common_parent(const node_t*a,const node_t*b)
{
	node_t*stack_a=0,*intr=a;
	node_t*stack_b=0,*iter=b;
	while(a)
	{
		
	}
	while(b)
	{
		
	}
	node_linked_free(stack_b);
	node_linked_free(stack_a);
}
int main()
{
	node_t*tree=0;
	bst_add(&tree,3);
	bst_add(&tree,1);
	bst_add(&tree,4);
	bst_add(&tree,1);
	bst_add(&tree,5);
	bst_add(&tree,9);
	bst_add(&tree,2);
	bst_add(&tree,6);

	node_t*a=bst_search(&tree,6);
	node_t*b=bst_search(&tree,2);

	node_linked_search(tree,dump,0);
	return 0;
}
