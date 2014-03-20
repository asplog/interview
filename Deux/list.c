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
		while(root->next)root=root->next;
		root->next=malloc(sizeof(node_t));
		root->next->next=0;
		root->next->value=value;
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

