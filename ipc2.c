#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void main() {
    int fd[2];
  
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);

        int suma = 0;
        int numerosRecibidos;
         char entrada[10];
    

        while (read(fd[0],&entrada, sizeof(entrada)))
        {
            if (strcmp(entrada, "+") != 0 ) {
                    numerosRecibidos = atoi(entrada);
                    suma = suma + numerosRecibidos;
            }else{
                printf("Caracter recibido : %s \n", entrada);
            }
            

        }
       
        printf("La suma total es igual a: %d \n" , suma);
        
        close(fd[0]);
        printf("HIJO ha terminado \n");

    }
    else {
        // PADRE: solo escribe
        close(fd[0]);
        char entrada[10];
    
        do{   
          printf("Dame un número (Indica el signo para la finalizacizacición ): ");
          scanf("%s", entrada);

                    write(fd[1], &entrada, sizeof(entrada));
                

        
        } while (strcmp(entrada, "+") != 0);


        
       
        close(fd[1]); 

        
        wait(NULL);
        printf("PADRE ha terminado \n");

    }


}
