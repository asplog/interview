typedef struct node
{
	struct node*next;
	int value;
}
node_t;
node_t*	list_append(node_t*,int value);
void	list_free(node_t*);
void	list_dump(const node_t*);

