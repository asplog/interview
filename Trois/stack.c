#include<stdlib.h>
#include"node.h"
void stack_push(node_t**stack,int value)
{
	node_t*node=malloc(sizeof*node);
	node->value=value;
	node->next=(*stack);
	(*stack)=node;
}
int stack_pop(node_t**stack)
{
	node_t*node=(*stack);
	int value=node->value;
	(*stack)=node->next;
	free(node);
	return value;
}
int stack_peek(node_t**stack)
{
	return(*stack)->value;
}
int stack_isEmpty(node_t**stack)
{
	return!*stack;
}
