#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void sort_two_group(node_t*root,int arg)
{
	node_t*S=0,*s=0;
	node_t*B=0,*b=0;
	node_t*iter=0;
	iter=root;
	while(iter)
	{
		if(arg<iter->value)
		{
			printf("B:%d\n",iter->value);
			B=list_append(B,iter->value);
			list_dump(B);
		}
		else
		{
			printf("S:%d\n",iter->value);
			S=list_append(S,iter->value);
			list_dump(S);
		}
		iter=iter->next;
	}
	list_dump(S);
	list_dump(B);
	s=S;
	b=B;
	while(root)
	{
		if(s)
		{
			root->value=s->value;
			s=s->next;
		}
		else
		if(b)
		{
			root->value=b->value;
			b=b->next;
		}
		root=root->next;
	}		
}
int main()
{	
	node_t*list=list_append(0,3);
	list_append(list,1);
	list_append(list,4);
	list_append(list,1);
	list_append(list,5);
	list_append(list,9);
	list_append(list,2);
	list_append(list,6);
	list_append(list,5);
	list_dump(list);

	sort_two_group(list,3);

	list_dump(list);	
	return 0;
}

