#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
     pid_t p1, p2, p3;
    
    int suma = 0;
    int suma2 = 0;
     p2 = fork();

     if (p2 == 0){
        for (int i = 1; i <= 100; i++){
            suma = suma + i;
        }
        printf("%d \n" , suma);
            p2 = getpid();
             printf("Soy P2 mi PID es : %d \n",p2);


        }else{
            p3 = fork();
            if(p3==0){
                for (int j = 101; j <= 200; j++){
                suma2 = suma2 + j;
                 
            }
            printf("%d \n" , suma2);
            p3 = getpid();
             printf("Soy P3 mi PID es : %d \n",p3);
            
        }else{
            p2 = wait(NULL);
            p3 = wait(NULL);
            printf("Todos los cálculos han finalizado \n");
            p1 = getpid();
            printf("Soy P1 mi PID es : %d \n",p1);
        }
            
    }

}















