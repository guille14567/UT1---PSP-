#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    
    time_t t;
    const char *fifo = "canal_num";
    const char *fifo2 = "canal_num";
   
    // Crear FIFO si no existe
    mkfifo(fifo, 0666);
    mkfifo(fifo2, 0666);

    int numero1;
    srand((unsigned) time(&t));
    numero1=rand() % 10;  

    // Abrir FIFO para escritura (bloquea hasta que el lector abra)
    int fd1 = open(fifo, O_WRONLY);
    if (fd1 == -1) {
        printf("escritor: error al abrir FIFO");
        
    }

    // Escribir el número en la FIFO
    if (write(fd1, &numero1, sizeof(numero1)) == -1) {
        printf("escritor: error al escribir");
        close(fd1);
    } else {
        printf(" Número %d enviado al fifo12.\n", numero1);
    }
  
    // Abrir FIFO para lectura (bloquea hasta que el escritor escriba)
    int fd2 = open(fifo2, O_RDONLY);
    if (fd2 == -1) {
        printf("lector: error al abrir FIFO");
      
    }

       int factorial;
    // Leer el número enviado
    if (read(fd2, &factorial, sizeof(factorial)) == -1) {
        printf("lector: error al leer");
        close(fd2);
      
    }

 
    printf("Número recibido: %d\n", factorial);
    if (factorial == 0)
    {
        printf("EL factorial de 0,  es 1 ");
    }
    
    printf("EL factorial de %d,  es %d \n", numero1,factorial);

    unlink("canal_num");
    printf("Borrando PIPE");
    return 0;
    
   
}
