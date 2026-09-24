#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
  pid_t p2, p2_padre ,p3, p3_padre,
  pid_padre, pid_abuelo;

  p2 = fork();


  if (p2==0){
   
    p2_padre = getppid();
    p2 = getpid();
        printf("Mi PID es : %d \n",p2);
        printf("El PID de mi padre es es : %d \n",p2_padre);
        printf("Me duermo 3 segundos\n");
        sleep(3);
  }else{
    p3 = fork();
  
    if(p3==0){
        p3 = getpid();
        p3_padre = getppid();
        printf("Mi PID es : %d \n",p3);
        printf("El PID de mi padre es es : %d \n",p3_padre);
        printf("me duermo 1 segundos\n");
        sleep(1);
    }else{
        p2 = wait(NULL);
        p3 = wait(NULL);
        pid_padre = getpid();
        pid_abuelo = getppid();
        printf("Mi PID es : %d \n",pid_padre);
        printf("El PID de mi padre es : %d \n",pid_abuelo);
        printf("Todos mis hijos han terminado\n");
      }
  }

 
  

  

}
