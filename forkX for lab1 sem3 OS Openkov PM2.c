#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

  void DosmWork(char *name){
    const int Zn=5;
     for(int i=0; i<Zn; i++){
       sleep(rand()%4);
       printf(" Done pass %d or %s \n",i, name);
     }
  }

int main(int argc, char *argv[]){
    printf(" I am %d \n",(int)getpid());
  pid_t pid =fork();
  printf("FORK returned: %d \n",(int)pid);
    if(pid<0){
      printf(" Fork failed ");
    }
    if(pid==0){
      printf(" I am Child. My_pid %d\n",(int)getpid());
      DosmWork("child");
      exit(42);  // 42 <-- in this programm game with it
    }
      // In Parent
        printf(" I am Parent. Waiting Child to END ... \n");
        sleep(30); // time in sec
        DosmWork("parent"); // if=(//) here: ZOMBIE

    int status=0;
      pid_t childpid= wait(&status);
      printf(" PARENT knows child %d finished with status %d. \n",(int)childpid,status);
    int childReturnVaule= WEXITSTATUS(status);
      printf("   Return Value was %d \n",childReturnVaule);






    return 0;
}
