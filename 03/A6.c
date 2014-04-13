#include"node.h"
#include"stack.h"
void sortWithStacks(node_t**stack)
{
	node_t*S={0};
	node_t*L={0};
	while(!stack_isEmpty(stack))
	{
		while((!stack_isEmpty(&S))&&stack_peek(stack)<stack_peek(&S))stack_push(&L,stack_pop(&S));
		while((!stack_isEmpty(&L))&&stack_peek(&L)<stack_peek(stack))stack_push(&S,stack_pop(&L));
		if(stack_isEmpty(&S))stack_push(&S,stack_pop(stack));
		else stack_push(&L,stack_pop(stack));
	}
	while(!stack_isEmpty(&L))stack_push(&S,stack_pop(&L));
	while(!stack_isEmpty(&S))stack_push(stack,stack_pop(&S));
}
int main()
{
	node_t*stack={0};
	stack_push(&stack,3);
	stack_push(&stack,1);
	stack_push(&stack,4);
	stack_push(&stack,5);
	stack_push(&stack,9);
	stack_push(&stack,2);
	stack_push(&stack,6);

	sortWithStacks(&stack);
	node_linked_dump(stack);
	return 0;
}
