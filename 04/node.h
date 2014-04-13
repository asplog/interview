typedef struct node
{
	struct node*gauche;
	int value;
	struct node*droite;
	int padding;
}
node_t;
node_t*node_new(int value);
void node_linked_search(const node_t*,void(*)(const node_t*,void*),void*);
unsigned char node_linked_any(const node_t*,unsigned char(*)(const node_t*,void*),void*);
unsigned char node_linked_all(const node_t*,unsigned char(*)(const node_t*,void*),void*);
void node_linked_dump_lsr(node_t*);
void node_linked_free(node_t*);
