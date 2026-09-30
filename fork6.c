#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
  pid_t p2 ,p3, p3_padre;

  p2 = fork();


  if (p2==0){
   
  
    p2 = getpid();

        printf("Me duermo 10 segundos\n");
        sleep(10);
        printf("Despierto\n");

  }else{
    
    p3 = fork();
  
    if(p3==0){
        p3 = getpid();
        p3_padre = getppid();
        printf("Soy el P3 ");
        printf("Mi PID es : %d \n",p3);
        printf("El PID de mi padre es es : %d \n",p3_padre);
        printf("me duermo 1 segundos\n");
        sleep(1);
    }else{
      p2 = wait(NULL);
      p3 = wait(NULL);
      printf("Soy padre de P2 y P3 y he esperado que terminasen para ejecutarme\n");

    }

 }
  

 
  

  

}