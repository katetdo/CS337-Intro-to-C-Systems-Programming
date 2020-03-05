#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(){
  int* queue = create_queue();
  word tail = 0;
  word size = 1;
  int choice=0;

  printf("\nA queue has been created.");
  printf("\nTo add an item, enter 1.");
  printf("\nTo remove an item, enter 2.");
  printf("\nTo print the queue, enter 3.");
  printf("\nTo know the size of the array enter 4");
  printf("\nTo exit enter -1");

  while(choice!=-1)
  {
    printf("\n\nPlease enter your choice: ");
    scanf("%d", &choice);

    if (choice==1)
    {
      int adding;
      printf("Please enter the value you want to add: ");
      scanf("%d", &adding);
      enqueue(&queue, &tail, &size, adding);
    }
    else if (choice==2)
    {
      int top = dequeue(&queue, &tail, &size);
      printf("%d has been dequeued\n", top);
    }
    else if (choice==3)
    {
      printQueue(queue, tail);
    }
    else if (choice==4)
    {
      printf("The size of the array is %d", size);
    }

  }
  free(queue);
  return 0;
}
