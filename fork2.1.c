#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t p1,p2,p3,p4,
    p2_padre,p4_padre;

    p2 = fork();

    if (p2 == 0){
        p2=getpid();
        p2_padre=getppid();
        printf("Soy p2, mi PID es : %d \n",p2);
        printf("Soy p2, el PID de mi padre es : %d \n",p2_padre);

    }else{
        p3 = fork();
            if(p3==0){
                p4 = fork();
                if(p4==0){
                p4=getpid();
                p4_padre=getppid();
                 printf("Soy p4, mi PID es : %d \n",p4);
                 printf("Soy p4, el PID de mi padre es : %d \n",p4_padre); 
                }else{
                waitpid(p4,NULL,0);
                p3=getpid();
                printf("Soy p3, mi PID es : %d \n",p3);
                }
            }else{
                waitpid(p2,NULL,0);
                waitpid(p3,NULL,0);
                p1 = getpid();
                printf("Soy P1, mi PID es : %d\n", p1);
            }
        
    }
}


a) ¿Cuál será el orden de ejecución de los procesos?¿Será siempre el mismo? Justifica la respuesta
El orden de ejecucción de los procesos será de forma, primero el que no tiene más hijos y no ha de esperar a nadie , p2. Después p4, ya que p3 debe esperar a que este termine y por ultimo p3 y p1.
