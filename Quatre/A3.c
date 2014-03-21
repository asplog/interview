#include<stdio.h>
#include"tree.h"
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d,",arg->value);
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
void gen_short_tree(node_t**tree,const int*array,unsigned int length)
{
	unsigned int k=0,K=1;
	while(K<length)K<<=1;
	while(1<K)
	{	
		for(k=K/2;k<length;k+=K)
		{
			fprintf(stdout,"add: %d(%d)/%d\n",k,array[k],length);
			bst_add(tree,array[k]);	
		}
		K/=2;
	}
}
void gen_minimal_tree(node_t**,const int*array,unsigned int length)
{
	{
		unsigned int k,K;
		node_t*l=0;
		node_t*p=0;
		node_t*r=0;
		for(k=0,K=length;k<K;++k)
		{
			node_t*node=node_new(array[k]);
		}
	}
}
int main()
{
	int depth;
	node_t*tree=0;
	int values[]={2,3,5,7,11,13,17,19,23,29,31,37,41,47,53,59,61,67,71,73,79,89,91,93,97};
	//gen_short_tree(&tree,values,(sizeof values)/(sizeof*values));
	gen_minimal_tree(&tree,values,(sizeof values)/(sizeof*values),0);
	depth=node_get_balanced_height(tree,0);
	fprintf(stdout,"Tree is %s\n",0<depth?"balanced":"not balanced");
	node_linked_search(tree,dump,0);
	fprintf(stdout,"\n");
	node_linked_free(tree);
	return 0;
}
