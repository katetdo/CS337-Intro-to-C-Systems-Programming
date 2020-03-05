#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// a recursive data type definition
// serves as the nodes of a list
/*typedef struct node
{
  int id;
  char* name;
  struct node* next;
} node;
*/
// a new list is created by: node* head = NULL;


// add a new node to the front of the list
void add_front(node* *head, node* new_node)
{
  new_node->next = *head;
  *head = new_node;
}

// add a new node to the end of the list
void add_end(node* *head, node* new_node)
{
  node * temp = *head;
  while (temp->next!=NULL)
    temp=temp->next;
  new_node->next = temp->next;
  temp->next= new_node;
}



// remove and return the node at the front of the list or NULL if empty
node* rem_front(node* *head)
{
  node* returning = *head;
  *head = (*head)->next;
  return returning;
}


// remove and return the node at the end of the list or NULL if empty
node* rem_end(node* *head)
{
  if ((*head)->next==NULL)
  {
    node * temp = *head;
    *head=NULL;
    return temp;
  }
  node* temp = *head;
  while(temp->next->next!=NULL)
    temp = temp->next;
  node * returning = temp->next;
  temp->next=NULL;
  return returning;
}


// return the number of nodes in the list
int list_len(const node* head)
{
  const  node * temp = head;
  int i =0;
  while (temp)
  {
    ++i;
    temp=temp->next;
  }
  return i;

}
// print the data values of  all the nodes in the list (from start to end)
void print_list(const node* head)
{
  const node * temp = head;
  while(temp)
  {
    printf("\nId: %d  Name: %s", temp->id, temp->name);
    temp= temp->next;
  }
}
// free the entire list and set *head = NULL
void free_list(node* *head)
{
  node* temp;
  while(*head)
  {
    temp=*head;
    *head=(*head)->next;

    free((temp)->name);
    free(temp);
    temp=NULL;
  }
}


