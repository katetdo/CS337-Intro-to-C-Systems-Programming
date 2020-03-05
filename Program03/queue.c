#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int* create_queue()
{
  int* queue = (int*)malloc(sizeof(int)*1);
  return queue;
}

void enqueue(int* *queue, word* tail, word* size, const int new_value)
{
  *((*queue) + *tail) = new_value;
  ++*tail;
  if (isFull(*tail, *size))
    ensureCapacity(queue, size);
}

int dequeue(int* *queue, word* tail, word* size)
{
  int i;
  int returning = *queue[0];
  for (i=0; i<(*tail); ++i){
    (*queue)[i]=(*queue)[i+1];
  }
  (*queue)[*tail]=0;
  --(*tail);
  if(isHalf(*tail, *size))
    shrink(queue, size);
  return returning;
}


void ensureCapacity(int* *queue, word* curSize)
{
  int * tmp = (int*)malloc(sizeof(int)*((*curSize)*2));
  int i;
  for (i=0; i<*curSize;++i){
    tmp[i]= (*queue)[i];
  }
  free(*queue);
  *queue=tmp;
  *curSize=*curSize*2;

}


void shrink(int* *queue, word* curSize)
{
  int * tmp = (int*)malloc(sizeof(int)*(*curSize/2));

  int i;
  for (i=0; i<(*curSize/2); ++i)
    tmp[i]=(*queue)[i];
  free(*queue);
  *queue=tmp;
  *curSize=*curSize/2;
}


int isHalf(const word tail, const word size)
{
  if (tail<(size/2))
    return 1;
  return 0;
}


int isEmpty(const word tail)
{
  if (tail==0)
    return 1;
  return 0;
}


int isFull(const word tail, const word size)
{
  if (tail>=size)
    return 1;
  return 0;
}

void printQueue(int* queue, const word tail)
{
  int i;
  if(isEmpty(tail))
  {
    printf("The queue is empty.\n");
  }
  else
  {
    for (i=0; i<tail; ++i)
      printf("%d ", queue[i]);
  }
}
