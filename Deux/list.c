#include<stdio.h>
#include<stdlib.h>
#include"list.h"
node_t*	list_append(node_t*root,int value)
{
	if(!root)
	{
		root=malloc(sizeof(node_t));
		root->next=0;
		root->value=value;
	}
	else
	{
		node_t*iter=root;
		while(iter->next)iter=iter->next;
		iter->next=malloc(sizeof(node_t));
		iter->next->next=0;
		iter->next->value=value;
	}
	return	root;
}
void	list_free(node_t*root)
{
	if(root->next)list_free(root->next);
	free(root);
}
void	list_dump(const node_t*root)
{
	while(root)
	{
		fprintf(stderr,"%d%c",root->value,root->next?',':'\n');		
		root=root->next;
	}
}

