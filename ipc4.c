#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void main() {
    int fd[2];
    int fd2[2];
  
    pipe(fd);
    pipe(fd2);

    pid_t pid = fork();


       if (pid == 0) {
       
       
        int factorial;
        read(fd[0], &factorial , sizeof(factorial));
        for (int i = factorial - 1; i>0;i--){
            factorial = factorial * i;
        }
        write(fd2[1], &factorial , sizeof(factorial) );
        
        close(fd[0]); 
        close(fd2[1]);
        printf("HIJO ha terminado \n");

    }
    else {
        // PADRE: solo lee
       
        int numAleatorio = rand() % 11;

        write(fd[1], &numAleatorio , sizeof(numAleatorio) );
        printf("El proceso padre genera el numero %d en el pipe1 \n" , numAleatorio);

        int factorialLeido;
        read(fd2[0], &factorialLeido , sizeof(factorialLeido));

        printf("El factorial calculado por el proceso hijo: %d != %d \n" , numAleatorio , factorialLeido);
        close(fd[1]); 
        close(fd2[0]);
        
        wait(NULL);
        printf("PADRE ha terminado \n");

    }

}
