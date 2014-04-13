#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int list_from_integer_b(node_t*self,int value,int range)
{	
	int ret=1;
	if(value>range*10)
	{
		self->next=malloc(sizeof(node_t));
		ret=list_from_integer_b(self->next,value,range*10);
	}
	self->value=(value/ret)%10;
	return 10*ret;
}
node_t*add_two_list_b(const node_t*A,const node_t*B)
{
	const node_t*result=0,*a=A,*b=B;
	node_t *C;
	int	va=0,la=1,vb=0,lb=1;
	while(a)
	{
		va=va*10+a->value;
		a=a->next;
	}
	while(b)
	{
		vb=vb*10+b->value;
		b=b->next;
	}
	C=malloc(sizeof(node_t));
	list_from_integer_b(C,va+vb,1);	
	return C;
}
node_t*add_two_list_l(const node_t*a,const node_t*b)
{
	node_t*result=0;
	int	up=0;
	while(a||b)
	{
		int	value=up;
		if(a)
		{
			value+=a->value;
			a=a->next;	
		}
		if(b)
		{
			value+=b->value;
			b=b->next;
		}
		result=list_append(result,value%10);
		up=value/10;
	}
	return result;
}
int main()
{
	node_t*a=malloc(sizeof(node_t)),*b=malloc(sizeof(node_t)),*c=0;
	list_from_integer_b(a,1342,1);
	list_from_integer_b(b,248,1);
	list_dump(a);
	list_dump(b);
	c=add_two_list_b(a,b);
	list_dump(c);
	return 0;
}
