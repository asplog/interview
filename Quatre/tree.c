#include<stdlib.h>
#include"tree.h"
void bst_add(node_t**node,int value)
{
	if(*node)
	{
		if((*node)->value==value);
		else if(value<(*node)->value)bst_add(&(*node)->gauche,value);
		else if((*node)->value<value)bst_add(&(*node)->droite,value);
	}
	else*node=node_new(value);
}
node_t*bst_search(node_t**node,int value)
{
	node_t*result=0;
	if(*node)
	{
		if((*node)->value==value)result=*node;
		else if(value<(*node)->value)result=bst_search(&(*node)->gauche,value);
		else if((*node)->value<value)result=bst_search(&(*node)->droite,value);
	}
	return	result;
}
