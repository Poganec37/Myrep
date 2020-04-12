#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

/*
 Address to sort ==>  BUBsort.c
*/

int main(int argc, char *argv[]) {  // argc of numbers;  argv of text

   printf(" I am %d \n", (int)getpid());
   
     pid_t pid =fork();
   printf(" FORK returned: %d \n", (int)pid);
	  if(pid<0){
	      perror("FORK failed");
		  exit(1);
	    }
	  if(pid==0){
		    // Child exec's
			 char* args[]={"./sort", // name bubsort[bubsort.c=>> sort.c]
				 "-3","24","5","-78","56","18","35","41","19","-896" // in SORT  +Write here
				  "145","-956","95",  // in SORT
				 "0",NULL   // not in SORT
			 };
			   execv(args[0],args);
	    }
		
		  // Parent
		  // Parent work here ..
		 printf(" Parent work here \n");
          // Parent wait Child
        	printf("Parent wait Child \n");
           wait(NULL);			
		   
    return 0;	  
}