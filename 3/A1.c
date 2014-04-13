#include<stdio.h>
#define __STACK__SIZE__ 768
typedef struct stack3
{
	int buffer[__STACK__SIZE__];
	unsigned int depth[3];
}
stack3_t;
void stack_push(stack3_t*stack,int index,int value)
{
	stack->buffer[3*(stack->depth[index]++)+index]=value;
}
int stack_pop(stack3_t*stack,int index)
{
	return stack->buffer[3*(--stack->depth[index])+index];
}
void stack_dump(stack3_t stack)
{
	register int k,K;
	fprintf(stdout,"Depth: %d %d %d",stack.depth[0],stack.depth[1],stack.depth[2]);
	fprintf(stdout,"Data: ");
	for(k=0,K=__STACK__SIZE__;k<K;++k)
		fprintf(stdout,"%d%c",stack.buffer[k],k!=K-1?',':'\n');
}
int main()
{
	stack3_t stack={0};

	stack_push(&stack,0,1);
	stack_push(&stack,0,2);
	stack_push(&stack,0,3);
	stack_push(&stack,1,10);
	stack_push(&stack,1,20);
	stack_push(&stack,1,30);
	stack_push(&stack,2,100);
	stack_push(&stack,2,200);
	stack_push(&stack,2,300);


	fprintf(stdout,"%d\n",stack_pop(&stack,0));
	fprintf(stdout,"%d\n",stack_pop(&stack,1));
	fprintf(stdout,"%d\n",stack_pop(&stack,2));
	fprintf(stdout,"%d\n",stack_pop(&stack,0));
	fprintf(stdout,"%d\n",stack_pop(&stack,1));
	fprintf(stdout,"%d\n",stack_pop(&stack,2));

	return 0;
}
