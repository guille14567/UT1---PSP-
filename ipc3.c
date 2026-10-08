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
        // HIJO: solo escribe
        close(fd[0]);
        
        int numeros;
        int numeros2;
        for (int i = 0; i < 2; i++) {
            numeros = rand() % 101;
            numeros2 = rand() % 101;
            
        }
         write(fd[1], &numeros, sizeof(numeros));
          write(fd[1], &numeros2, sizeof(numeros2));
        printf("He mandado los dos numeros al padre \n");
        close(fd[1]);
        printf("HIJO ha terminado \n");

    }
    else {
        // PADRE: solo lee
        close(fd[1]);
        
        int numero1;
        int numero2;
        read(fd[0], &numero1, sizeof(numero1));
        read(fd[0], &numero2, sizeof(numero2));
      

        printf("Suma: %d + %d = %d \n " , numero1, numero2 , numero1 + numero2);
        printf("Resta: %d - %d = %d \n " , numero1, numero2 , numero1 - numero2);
        printf("Multiplicación: %d * %d = %d \n " , numero1, numero2 , numero1 * numero2);
        printf("División: %d / %d = %d \n " , numero1, numero2 , numero1 / numero2);
   
        close(fd[1]); 
        wait(NULL);
        printf("PADRE ha terminado \n");

    }


}
