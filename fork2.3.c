#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t p1,p2,p3,p4,p5,p6, p1_padre;

   p1 = getpid();
   p1_padre = getppid();

   p2 = fork();


   if(p2==0){
    p2 = getpid();
    p3=fork();
        if(p3 == 0){
            p5=fork();
            if(p5==0){
                printf("Soy p5 y mi PID %d \n", getpid());
                printf("Soy p5 y el PID de mi abuelo es :  %d \n", p2);
            }else{
                waitpid(p5,NULL,0);
                printf("Soy p3 y mi PID %d \n", getpid());
                printf("Soy p3 y el PID de mi abuelo es :  %d \n", p1);
            }
        }else{
            waitpid(p3,NULL,0);
            p4 = fork();
            if(p4==0){
                p6=fork();
                if(p6==0){
                    printf("Soy p6 y mi PID %d \n", getpid());
                    printf("Soy p6 y el PID de mi abuelo es :  %d \n", p2);
                }else{
                waitpid(p6,NULL,0);
                printf("Soy p4 y mi PID %d \n", getpid());
                printf("Soy p4 y el PID de mi abuelo es :  %d \n", p1);
                }
               

            }else{
                waitpid(p4,NULL,0);
                printf("Soy p2 y mi PID %d \n", getpid());
                printf("Soy p2 y el PID de mi abuelo es :  %d \n", p1_padre);
            }
        }
        
   }else{
         waitpid(p2, NULL, 0);

        printf("Soy p1 y mi PID es %d\n", getpid());
       
   }
  

}
