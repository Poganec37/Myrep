#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

/*
   format work is....     ./sort 80 10 -5 -890 0 
	     * END of line=0, SORT BEFORE 0(NULL)
--------------------------------------	  
  in: 	80 10 -5 -890
  out: -890 -5 10 80  
*/

int main(int argc, char *argv[]) {  // argc of numbers;  argv of text
   printf(" In FILE: \n");
      int key[argc];   
	
    printf("In ARGC \n");
	  for(int i=1; i<argc; i++){  // Mas[2]... Mas[N], N- the END of Mas
	     key[i]=atoi(argv[i]); // DO atoi {text in numbers}
		 printf("%d ",key[i]);
	  }
	  print("\n");
	  
	 printf("IN mas >> \n");
	   for(int i=1; i<argc-1; i++){  // qual(argc-1): the END is NULL
		 printf("%d ",key[i]);
	  }
	   int q;
	  // SORT of Bubble
	  for(int i=1; i<argc-1; i++){
		  for(int j=1; j<argc-i-1; j++){
			  if(key[j]>key[j+1]){
				  q=key[j];
				  key[j]=key[j+1];
				  key[j+1]=q;
			  }
		  }
	  }
	   printf("\n");
	   
	    printf("OUT mas >> \n");
	   for(int i=1; i<argc-1; i++){  // qual(argc-1): the END is NULL
		 printf("%d ",key[i]);
	  }

    return 0;	  
}