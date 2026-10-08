#include <stdio.h>
#include <unistd.h>
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
        printf("Carácter recibido: + \n");
        printf("La suma total es igual a: %d \n" , suma);

        close(fd[0]);
        printf("HIJO ha terminado \n");

    }
    else {
        // PADRE: solo escribe
        close(fd[0]);
        
        for (int i = 0; i < 3; i++) {
        int numeros = rand() % 101;
        write(fd[1], &numeros, sizeof(numeros));
        }
        close(fd[1]); 
        wait(NULL);
        printf("PADRE ha terminado \n");

    }


}
