#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void main() {
    pid_t p2,p3;
    int fd[2];
    int fd2[2];
    int fd3[2];
    int fd4[2];
  
    pipe(fd);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);

    p2 = fork();


    if (p2 == 0) {
    int numeroRecibidos[2];
    read(fd[0], numeroRecibidos , sizeof(numeroRecibidos));

    int suma = numeroRecibidos[0] + numeroRecibidos[1];
    
    write(fd3[1], &suma , sizeof(suma));
    

    }else {
        p3 = fork();
            if (p3 == 0) {
                 int numeroRecibidos[2];
                read(fd2[0], numeroRecibidos , sizeof(numeroRecibidos));
                int producto = numeroRecibidos[0] * numeroRecibidos[1];

                write(fd4[1], &producto , sizeof(producto));
            } else{
        
        
        
        
        printf("Soy P1 \n ");
        int num1;
        printf("Ingresa un número : ");
        scanf("%d", &num1);
        int num2;
        printf("Ingresa otro número: ");
        scanf("%d", &num2);
        int numeros[2] = {num1, num2};
   
        write(fd[1], numeros , sizeof(numeros));
        write(fd2[1], numeros , sizeof(numeros));
        
        
        int suma,producto;
        read(fd3[0], &suma , sizeof(suma));
        read(fd4[0], &producto , sizeof(producto));

        printf("P2 me ha mandado la suma de %d y %d y el resultado es  : %d \n", num1,num2,suma);
        printf("P3 me ha mandado la multiplicacion de %d y %d y el resultado es : %d \n ", num1,num2,producto);

            }
    }

}
