#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
  pid_t pid,pid_hijo,pid_padre;

  pid = fork();

  if (pid == 0){

    printf("Soy el proceso hijo y el alumno es Guillermo \n");

  }else{
   
    pid_hijo = wait(NULL);
     pid_padre = getpid();
    printf("Hola soy el padre \n");
    printf("Mi PID es : %d \n",pid_padre);
    printf("MI hijo tenia el PID : %d \n",pid_hijo);
   
  }
  exit(0);
}
