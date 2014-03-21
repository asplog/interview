typedef struct node
{
	struct node*next;
	int value;
}
node_t;
node_t*node_new(int);
void node_linked_free(node_t*);
void node_linked_dump(node_t*);
void node_linked_dump_r(node_t*);

