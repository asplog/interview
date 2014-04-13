#include<stdio.h>
#include"node.h"
#include"stack.h"
void dumpTowers(node_t**towers)
{
	fprintf(stdout,"---------");
	node_linked_dump_r(towers[0]);
	node_linked_dump_r(towers[1]);
	node_linked_dump_r(towers[2]);
	fprintf(stdout,"\n");
}
void moveDisk(node_t**base,int s,int d)
{
//	if(!stack_isEmpty(base+s))
		stack_push(base+d,stack_pop(base+s));
}
void moveDisks(node_t**towers,int depth,int src,int dst,int buf)
{
	if(depth<=0)return;
	moveDisks(towers,depth-1,src,buf,dst);
	moveDisk(towers,src,dst);
	moveDisks(towers,depth-1,buf,dst,src);
	dumpTowers(towers);
}
int main()
{
	
	node_t*tower[3]={0};

	stack_push(tower+0,29);
	stack_push(tower+0,23);
	stack_push(tower+0,19);
	stack_push(tower+0,17);
	stack_push(tower+0,13);
	stack_push(tower+0,11);
	stack_push(tower+0,7);
	stack_push(tower+0,5);
	stack_push(tower+0,3);
	stack_push(tower+0,2);
	dumpTowers(tower);

	moveDisks(tower,9,0,1,2);
	dumpTowers(tower);

	return 0;
}
