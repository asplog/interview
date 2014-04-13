#include<stdio.h>
#include"tree.h"
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d",arg->value);
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
	node_linked_search(tree,dump,0);
	return 0;
}
