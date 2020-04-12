#include <stdio.h>
#include <stdlib.h>



int main()
{
    char A[80];
    char *t;
    printf("maz A in>> \n");
    gets(A);
    t=A;
    int i;
    printf("maz A >> \n");
  for (i=0; i<=10; i++){
    printf("%c ",A[i]);
  }
  printf("\n maz t=A >> \n");
  for (i=0; i<=10; i++){
    printf("%c ",t[i]);
  }





    return 0;
}
