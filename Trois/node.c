#include<stdio.h>
#include<stdlib.h>
#include"node.h"
node_t*node_new(int arg)
{
	node_t*node=malloc(sizeof*node);
	node->next=0;
	node->value=arg;
	return node;
}
void node_linked_dump(node_t*node)
{
	while(node)
	{
		fprintf(stdout,"%d%c",node->value,node->next?',':'\n');
		node=node->next;
	}
	fprintf(stdout,"\n");
	return;	
}
void node_linked_dump_r(node_t*node)
{
	if(node)
	{
		node_linked_dump_r(node->next);
		fprintf(stdout,"%d,",node->value);
	}
	else	fprintf(stdout,"\n");
	return;	
}
void node_linked_free(node_t*node)
{
	while(node)
	{
		node_t*next=node->next;
		free(node);
		node=next;
	}
	return;	
}
