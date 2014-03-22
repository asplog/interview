#include<stdio.h>
#include"tree.h"
#include<math.h>
void dump(const node_t*arg,void*opts)
{
	fprintf(stdout,"%d",arg->value);
}
void find_path_sum()
{

}
int main()
{
	double p=M_PI*0.2;
	int k=0;
	node_t*tree=0;
	for(k=0;k<12;++k)
	{
		int v=((int)(p*=10.0))%10;
		bst_add(&tree,v);
		p=fmod(p,1.0);
	}
	node_linked_search(tree,dump,0);
	fprintf(stdout,"\n");
	return 0;
}
