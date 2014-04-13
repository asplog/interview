#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void cut_this(node_t*node)
{
	node_t*buff=node->next;
	node->value=buff->value;
	node->next=buff->next;
	free(buff);
}
int main()
{	
	node_t*list=list_append(0,3);
	list_append(list,1);
	list_append(list,4);
	list_append(list,1);
	list_append(list,5);
	list_append(list,9);
	list_append(list,2);
	list_append(list,6);
	list_append(list,5);
	list_dump(list);

	cut_this(list->next->next);
	list_dump(list);	
	return 0;
}

