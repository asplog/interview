#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node*next;
	int value;
}
node_t;
node_t*node_new(int arg)
{
	node_t*node=malloc(sizeof*node);
	node->value=arg;
	node->next=0;
	return node;
}
typedef struct setOfStacks
{
	int	maxDepth;
	int	curDepth;
	node_t*	stacks;
}
stacks_t;
void stacks_push(stacks_t*stacks,int value)
{
	node_t*word=node_new(value);
	if(curDepth<maxDepth)
	{
		if(stacks->value)
		{
			node_t*stack=stacks->value;
		}
		else
		{
			
		}
	}
	else
	{
		
	}
}
int stacks_pop(stacks_t*self)
{

}
int main()
{
	stacks_t stacks={0};
	stacks.maxDepth=4;
	stacks_push(&stacks,3);
	stacks_push(&stacks,1);
	stacks_push(&stacks,4);
	stacks_push(&stacks,1);
	stacks_push(&stacks,5);
	stacks_push(&stacks,9);
	stacks_push(&stacks,2);
	stacks_push(&stacks,6);
	return 0;
}

