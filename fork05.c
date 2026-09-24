#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
  pid_t p1,p2,p3,
  p2_pid,p2_pidpadre,
  p3_pid,p3_pidpadre,
  p1_padre;

  p2 = fork();

    if(p2==0){
        p3=fork();
         if (p3==0){
        p3_pid = getpid();
        p3_pidpadre = getppid();
        printf("Soy P3 mi PID es : %d \n",p3_pid);
        printf("El PID de mi padre es es : %d \n",p3_pidpadre);
        }else{
        p3 = wait(NULL);
         p2_pid = getpid();
         p2_pidpadre = getppid();
        printf("Soy P2 mi PID es : %d \n",p2_pid);
        printf("El PID de mi padre es es : %d \n",p2_pidpadre);
        }
        
       
    }else{
        p2 = wait(NULL);
        p1= getpid();
        p1_padre = getppid();
        printf("Soy P1 mi PID es : %d \n",p1);
        printf("El PID de mi padre es es : %d \n",p1_padre);
    }


  

 
  

  

}
