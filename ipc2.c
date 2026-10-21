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

        while (read(fd[0],&numerosRecibidos, sizeof(numerosRecibidos)))
        {

            printf("Numero a sumar:  %d\n", numerosRecibidos);
            suma = suma + numerosRecibidos;

        }
       
        printf("La suma total es igual a: %d \n" , suma);

        close(fd[0]);
        printf("HIJO ha terminado \n");

    }
    else {
        // PADRE: solo escribe
        close(fd[0]);

        int numerosLeidos;
        char entrada[10];
   
        do
        {   
          printf("Dame un número (Dame --> +,-,/,* -- Indicará el signo y terminará de recibir número): ");
          scanf("%s", entrada);

                if (strcmp(entrada, "+") != 0 ) {
                    numerosLeidos = atoi(entrada);
                    write(fd[1], &numerosLeidos, sizeof(numerosLeidos));
                }   

        } while (strcmp(entrada, "+") != 0);
       
        
        
        
       
        close(fd[1]); 
        wait(NULL);
        printf("PADRE ha terminado \n");

    }


}
