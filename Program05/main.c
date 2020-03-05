#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

node* make_node(int id, char * name)
{
  node* n =(node*)malloc(sizeof(node));
  n->id = id;
  n->name = strdup(name); //malloc
  return n;
}

int main (int args, char* argv []){
  node * head;
  node * new_node;
  node * returned;
  int id;
  char name [256];
  int choice = 0;
  //create a new empty list
  head = NULL;

  printf("\nTo add to the front of the list, enter 1.");
  printf("\nTo add to the end of the list, enter 2.");
  printf("\nTo remove from the front of the list, enter 3.");
  printf("\nTo remove from the end of the list, enter 4.");
  printf("\nTo get the number of nodes in the list, enter 5.");
  printf("\nTo print the list, enter 6.");
  printf("\nTo add in order, enter 7");
  printf("\nTo remove a certain key, enter 8");
  printf("\nTo exit, enter -1.");

  while(choice!=-1)
  {
    printf("\nPlease enter your choice: ");
    scanf("%d", &choice);
    if (choice==1 || choice==2)
    {
      printf("\nPlease enter the id of the new node: ");
      scanf("%d", &id);
      printf("\nPlease enter the name for the new node: ");
      scanf("%s", name);
      new_node = make_node(id, name);
      if (choice==1 || head==NULL)
        add_front(&head, new_node);
      else if (choice==2)
	add_end(&head, new_node);
    }
    else if (choice==3 || choice==4)
    {
      if(head==NULL)
        printf("\nThe list is empty\n");
      else if (choice==3)
      {
        returned = rem_front(&head);
        printf("\nThe node returned.");
        printf("\nId: %d Name: %s", returned->id, returned->name);
      }
      else if (choice==4)
      {
        returned = rem_end(&head);
        printf("\nThe node returned.");
        printf("\nId: %d Name: %s", returned->id, returned->name);
      }
    }
    else if (choice==5)
    {
      int num = list_len(head);
      printf("\nThe length of the list is: %d\n", num);
    }
    else if (choice==6)
    {
      print_list(head);
    }
    else if (choice==7)
    {
      printf("\nPlease enter the id of the new node: ");
      scanf("%d", &id);
      printf("\nPlease enter the name for the new node: ");
      scanf("%s", name);
      new_node = make_node(id, name);
      add_inorder(&head, new_node);
    }
    else if (choice==8)
    {
      printf("\nPlease enter the key you're looking for: ");
      scanf("%s", name);
      node* returned = rem_inorder(&head, name);
      printf("\nReturned node, id: %d, name: %s", returned->id, returned->name);
    }
  }

  free_list(&head);
  return 0;
}

