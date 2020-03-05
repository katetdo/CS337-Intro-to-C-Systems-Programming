#include <stdio.h>
#include <stdlib.h>

int factor_power(int d, int* n);

int main(){
  
  int n;
  int* nptr = &n;
  //Get number larger than 1
  do{
    printf("\nEnter a number larger than 1: ");
    scanf("%d", &n);
  }while(n<=1);

  printf("n = ");

  //Factorization
  int d = 2;
  while (d<=n)
  {
    if (n%d == 0)
    {
     int e;
     e =  factor_power(d, nptr);
     printf("%d", d);
     printf("^");
     printf("%d", e);
     if(d<=n)
       {printf(" * ");}
    }
  ++d;
  }
  printf("\n\n");
  return 0;
}

int factor_power(int d, int* n){
   int e = 0;
   do
    {
      ++e;
     *n/=d;
    } while (*n%d==0);

  return e;
}

