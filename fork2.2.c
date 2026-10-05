#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t p1,p2,p3,p4, p1_acumulado,
    p2_acumulado,p3_acumulado,p4_acumulado;

    p2 = fork();

    if (p2==0){
        
        p3 = fork();
        if (p3==0){
        
            p4 = fork();
            if(p4==0){
            printf("Soy p4 y mi PID es %d \n" , getpid());
            printf("Soy p4 y mi PPID es %d \n" , getppid());
            p4_acumulado = getpid() + getppid();
            printf(" PIDS acumulados %d \n" , p4_acumulado);
            }
        }else{
            waitpid(p4,NULL,0);
            printf("Soy p3 y mi PID es %d \n" , getpid());
            printf("Soy p3 y mi PPID es %d \n" , getppid());
            p3_acumulado = getpid() + getppid();
            printf(" PIDS acumulados %d \n" , p3_acumulado);
        }
        
    }else{
        waitpid(p3,NULL,0);
            printf("Soy p2 y mi PID es %d \n" , getpid());
            printf("Soy p2 y mi PPID es %d \n" , getppid());
            p2_acumulado = getpid() + getppid();
            printf(" PIDS acumulados %d \n" , p2_acumulado);

        waitpid(p2,NULL,0);
            printf("Soy p1 y mi PID es %d \n" , getpid());
            printf("Soy p1 y mi PPID es %d \n" , getppid());
            p1_acumulado = getpid() + getppid();
            printf(" PIDS acumulados %d \n" , p1_acumulado);    
        
    }
    

}
