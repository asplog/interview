#include<stdio.h>
#include<stdlib.h>
#include"node.h"
node_t*node_new(int arg)
{
	node_t*node=malloc(sizeof*node);
	node->gauche=0;
	node->value=arg;
	node->droite=0;
	node->padding=0;
	return node;
}
void node_linked_search(const node_t*node,void(*func)(const node_t*,void*),void*opts)
{
	if(node->gauche)node_linked_search(node->gauche,func,opts);
	(*func)(node,opts);
	if(node->droite)node_linked_search(node->droite,func,opts);
}
unsigned char node_linked_any(const node_t*node,unsigned char(*comp)(const node_t*,void*),void*opts)
{
	unsigned char result=0;
	if(node)
	{
		result|=node_linked_any(node->gauche,comp,opts);
		result|=(*comp)(node,opts);
		result|=node_linked_any(node->droite,comp,opts);
	}
	return result;
}
unsigned char node_linked_all(const node_t*node,unsigned char(*comp)(const node_t*,void*),void*opts)
{
	unsigned char result=1;
	if(node)
	{
		result&=node_linked_all(node->gauche,comp,opts);
		result&=(*comp)(node,opts);
		result&=node_linked_all(node->droite,comp,opts);
	}
	return result;
}
void node_linked_dump_lsr(node_t*node)
{
	
}
void node_linked_free(node_t*node)
{
	if(node->gauche)node_linked_free(node->gauche);
	if(node->droite)node_linked_free(node->droite);
	free(node);	
}
