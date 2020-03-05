#include <stdlib.h>
#include <stdio.h>
#include "histo.h"

int i;

void init_histogram(int histo[])

{
  for(i=0; i<LETTERS; ++i)
    histo[i]=0;
}


void cons_histogram(const char string[], int histo[])
{
  i=0;
  char c = string[i];
  while(c)
  {
    if (c>='a' && c<='z')
      ++histo[c-'a'];
    ++i;
    c = string[i];
  }
}


void most_frequent(const int histo[], char* ret_val)
{
  printf ("%c occurred most often\n", *ret_val);
}


void display_histogram(int* const histo)
{
  char freq=0;
  char* freqPtr = &freq;
  for (i=0; i<LETTERS; ++i)
  {
    if (histo[i]>0)
    {
      printf("%c appeared ", (i+'a'));
      printf("%d", histo[i]);
      if (histo[i]>1)
        printf(" times\n");
      else
	printf(" time\n");
      if (histo[i]>histo[(int)freq])
	freq=i;
    }
  }
  freq+='a';
  most_frequent(histo, freqPtr);
}

