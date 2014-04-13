#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"stack.h"
int main()
{
	node_t*stack=0,*picker=0,*buffer=0,*ans=0;
	stack_push(&stack,3);
	stack_push(&stack,1);
	stack_push(&stack,4);
	stack_push(&stack,1);
	stack_push(&stack,5);
	stack_push(&stack,9);
	stack_push(&stack,2);
	stack_push(&stack,6);

	while(!stack_isEmpty(&stack))
	{
		int value=stack_pop(&stack);
		while(!stack_isEmpty(&ans)&&stack_peek(&ans)<value)
		{
			stack_push(&stack,stack_pop(&ans));
		}
		stack_push(&ans,value);
	}
/*	
	while(!stack_isEmpty(&stack))
	{
		while(!stack_isEmpty(&stack))
		{
			int value=stack_pop(&stack);
			if(stack_isEmpty(&picker)||stack_peek(&picker)<=value)stack_push(&picker,value);
			else stack_push(&buffer,value);
		}
		while(!stack_isEmpty(&buffer))
		{
			int value=stack_pop(&buffer);
			if(stack_isEmpty(&picker)||stack_peek(&picker)<=value)stack_push(&picker,value);
			else stack_push(&stack,value);
		}
		stack_push(&ans,stack_pop(&picker));
		while(!stack_isEmpty(&picker))stack_push(&stack,stack_pop(&picker));
	}
*/
	node_linked_dump(ans);
	return 0;
}
