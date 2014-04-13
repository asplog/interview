#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node*next;
	int value;
}
node_t;
node_t*node_new(int value)
{
	node_t*self=malloc(sizeof(node_t));
	self->next=0;
	self->value=value;
	return self
}
int main()
{
	return 0;
}
