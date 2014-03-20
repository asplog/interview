#include<stdio.h>
#include<stdlib.h>
typedef struct __node
{
	struct __node*next;
	char value;	
}
node;
void append(node*root,node*const arg)
{
	while(root->next)root=root->next;
	root->next=arg;	
}
node*new(const char arg)
{
	node*v=malloc(sizeof(node));
	v->next=0;
	v->value=arg;
	return v;
}
void dump(node*root)
{
	while(root)
	{
		fprintf(stdout,"%c%c",root->value,root->next?',':'\n');
		root=root->next;
	}
}
int main()
{	
	node*root=new('3');
	append(root,new('1'));	
	append(root,new('4'));	
	append(root,new('1'));	
	append(root,new('5'));	
	append(root,new('9'));	
	append(root,new('2'));	
	dump(root);
	return 0;
}
