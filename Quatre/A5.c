#include<stdio.h>
#include"tree.h"
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d",arg->value);
}
unsigned char bst_check(const node_t*node,void*opts)
{
	unsigned char result=*(int*)opts<node->value;
	fprintf(stdout,"%d < %d(%d)\n",*(int*)opts,node->value,result);
	*(int*)opts=node->value;
	return result;
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

	bst_search(&tree,9)->droite=node_new(1);
	node_linked_search(tree,dump,0);
	
	int lvalue=1<<((sizeof(int)<<3)-1);
	int bst=node_linked_all(tree,bst_check,&lvalue);

	fprintf(stdout,"\n%d\n",bst);	

	return 0;
}
