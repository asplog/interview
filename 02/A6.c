#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node*next;
	unsigned int value;
}
node_t;
node_t*node_new(int arg)
{
	node_t*node=malloc(sizeof(node));
	node->next=0;
	node->value=arg;
	return node;
}
node_t;
int stack_has_value(node_t*self,int value)
{
	int result=0;
	if(self)
	{
		result=self->value==value;
		result|=stack_has_value(self->next,value);
	}
	return result;
}
int node_is_cyclic(node_t*arg)
{
	int result=0;
	node_t*stack=0;
	while(!result&&arg)
	{
		node_t*word=malloc(sizeof(node_t));
		result|=stack_has_value(stack,arg);
		word->value=(unsigned int)arg;
		word->next=stack;
		stack=word;	
		fprintf(stdout,"%c,",arg->value);
		arg=arg->next;
	}
	fprintf(stdout,": is %s\n",result?"cyclic":"not cyclic");	
	return result;
}
int main()
{
	node_t*a=node_new('a');
	node_t*b=node_new('b');
	node_t*c=node_new('c');
	node_t*d=node_new('d');
	node_t*e=node_new('e');
	a->next=b;
	b->next=c;
	c->next=d;
	node_is_cyclic(a);
	d->next=e;
	e->next=c;
	node_is_cyclic(a);
	
	return 0;
}
