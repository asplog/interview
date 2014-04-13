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
	node_t*node=malloc(sizeof*node);
	node->value=value;
	node->next=0;
	return node;
}
int recur(node_t**bt,node_t*cur)
{
	int result=1;
	if(cur->next)result&=recur(bt,cur->next);
	if((*bt)!=cur||(*bt)->next!=cur)
	{
		result&=(*bt)->value==cur->value;
		(*bt)=(*bt)->next;
	}	
	return result;
}
int list_is_mirror(node_t*list)
{
	int result=1;
	node_t*b=list;
	node_t*e=list;
	return recur(&b,e);
}
int main()
{
	node_t*n0=node_new('0');
	node_t*n1=node_new('1');
	node_t*n2=node_new('2');
	node_t*n3=node_new('1');
	node_t*n4=node_new('0');
	node_t*n5=node_new('1');	
	n0->next=n1;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	fprintf(stdout,"%d\n",list_is_mirror(n0));
	n4->next=n5;
	fprintf(stdout,"%d\n",list_is_mirror(n0));

	
	return 0;
}
