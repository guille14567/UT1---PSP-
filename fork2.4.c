#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t p1,p2,p3,p4,p5, p2_acumulado,
    p3_acumulado,p4_acumulado,p5_acumulado;

    int acumulado = getpid();
    printf("pid padre %d \n" , getpid());
    p2 = fork();
    
    if(p2==0){
        p5 = fork();
            if(p5==0){
                
                    if(getpid() %2 == 0){
                        p5_acumulado = acumulado + 10;
                        printf("Soy p5 y al ser par sumo 10 : %d  \n" , p5_acumulado );
                    }else{
                        p5_acumulado = acumulado - 100;
                        printf("Soy p5 y al ser impar resto 100 : %d  \n" , p5_acumulado );
                    }
            }else{
            waitpid(p5,NULL,0);
            
                    if(getpid() %2 == 0){
                        p2_acumulado = acumulado + 10;
                        printf("Soy p2 y al ser par sumo 10 : %d  \n" , p2_acumulado );
                    }else{
                        p2_acumulado = acumulado - 100;
                        printf("Soy p2 y al ser impar resto 100 : %d  \n" , p2_acumulado );
                    }
        }
    }else{
        p3 = fork();
            if(p3==0){
                p4 = fork();
                if(p4==0){
                
                    if(getpid() %2 == 0){
                        p4_acumulado = acumulado + 10;
                        printf("Soy p4 y al ser par sumo 10 : %d  \n" , p4_acumulado );
                    }else{
                        p4_acumulado = acumulado - 100;
                        printf("Soy p4 y al ser impar resto 100 : %d  \n" , p4_acumulado );
                    }
            }else{
                waitpid(p4,NULL,0);
                
                    if(getpid() %2 == 0){
                        p3_acumulado = acumulado + 10;
                        printf("Soy p3 y al ser par sumo 10 : %d  \n" , p3_acumulado );
                    }else{
                        p3_acumulado = acumulado - 100;
                        printf("Soy p3 y al ser impar resto 100 : %d  \n" , p3_acumulado );
                    }
            }
        }else{
        waitpid(p2,NULL,0);
        waitpid(p3,NULL,0);
        
        }
    }
}
        
    

    

