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

    pid_hijo = getpid();
    pid_padre = getppid();

    printf("Soy el proceso HIJO\n");
    printf("Mi PID es : %d \n",pid_hijo);
    printf("El PID de mi padre es : %d \n",pid_padre);


  }else{
   
    pid_hijo = wait(NULL);
    pid_padre = getpid();
    printf("Soy el proceso PADRE\n");
    printf("Mi PID es : %d \n",pid_padre);
    printf("MI hijo tenia el PID : %d \n",pid_hijo);
    printf("El proceso hijo ha terminado\n");
  }
  exit(0);
}
