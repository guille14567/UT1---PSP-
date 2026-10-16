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
       
        close(fd[0]); 

        int numDNI;
        printf("Ingresa tu DNI sin la letra: ");
        scanf("%d", &numDNI);
        if(numDNI < 10000000 || numDNI > 99999999){
            printf("numero incorrecto");
            exit(0);
        }
        write(fd[1], &numDNI , sizeof(numDNI));
        
        char letra;
        read(fd2[0], &letra , sizeof(letra));
         printf("DNI : %d \n" , numDNI);
         printf("Letra :  %c \n" , letra);


    }else {
        
        int DNI;
        read(fd[0], &DNI , sizeof(DNI));

        int calculo;
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
     
        DNI %=23;
        char letraCalculada = letra[DNI];
        

        write(fd2[1], &letraCalculada , sizeof(letraCalculada));
        


    }

}
