// a recursive data type definition
// serves as the nodes of a list
typedef struct node
{
  int id;
  char* name;
  struct node* next;
} node;

// create an empty list - set *node = NULL
void create_list(node** head);

// add a new node to the front of the list
void add_front(node* *head, node* new_node);
// add a new node to the end of the list
void add_end(node* *head, node* new_node);


// add a new node in the list, in (ascending) sorted order based on
// the nodes name component's value
void add_inorder(node* *head, node* new_node);

// remove and return the first node in the list whose name component's value
// is equal to the given key_name
// return NULL if no such node exists in the list
node* rem_inorder(node* *head, char* key_name);

// remove and return the node at the front of the list or NULL if empty
node* rem_front(node* *head);
// remove and return the node at the end of the list or NULL if empty
node* rem_end(node* *head);

// return the number of nodes in the list
int list_len(const node* head);

// print the data values of  all the nodes in the list (from start to end)
void print_list(const node* head);

// free the entire list and set *node = NULL 
void free_list(node* *head);

