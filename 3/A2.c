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
	return self;
}
typedef struct stack
{
	node_t*stack;
	node_t*min;
}
stackMin_t;
void stack_push(stackMin_t*stack,int value)
{
	{
		node_t*word=node_new(value);
		word->next=stack->stack;
		stack->stack=word;
	}
	{
		if(stack->min)
		{
			if(stack->min->value>=value)
			{
				node_t*word=node_new(value);
				word->next=stack->min;
				word->value=value;
				stack->min=word;			
			}
		}
		else
		{
			stack->min=node_new(value);
		}
	}
}
int stack_pop(stackMin_t*stack)
{
	int result;
	if(stack->stack->value==stack->min->value)
	{
		node_t*word=stack->min;
		stack->min=word->next;
		free(word);
	}
	node_t*word=stack->stack;
	stack->stack=word->next;
	result=word->value;
	free(word);
	return result;
}
int stack_min(stackMin_t*stack)
{
	return stack->min->value;
}
int main()
{
	stackMin_t stack={0};
	stack_push(&stack,3);
	stack_push(&stack,1);
	stack_push(&stack,4);
	stack_push(&stack,1);
	stack_push(&stack,5);

	fprintf(stdout,"Min: %d\n",stack_min(&stack));
	fprintf(stdout,"pop: %d\n",stack_pop(&stack));
	fprintf(stdout,"pop: %d\n",stack_pop(&stack));
	fprintf(stdout,"Min: %d\n",stack_min(&stack));
	fprintf(stdout,"pop: %d\n",stack_pop(&stack));
	fprintf(stdout,"pop: %d\n",stack_pop(&stack));
	fprintf(stdout,"Min: %d\n",stack_min(&stack));

	return 0;
}
