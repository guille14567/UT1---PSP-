#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    
    time_t t;
    const char *pipe02 = "pipe02";
    
   
  
    mkfifo(pipe02, 0666);
  

    int numero;
    srand((unsigned) time(&t));
    numero=rand() % 10;  


    int fd = open(pipe02, O_WRONLY);
    if (fd == -1) {
        printf("IMposible escribir ");
        
    }

   
    if (write(fd, &numero, sizeof(numero)) == -1) {
        printf("escritor: error al escribir");
        close(fd);
    } else {
        printf(" Número %d enviado al fifo12.\n", numero);
    }
  
    
    fd = open(pipe02, O_RDONLY);
    if (fd == -1) {
        printf("lector: error al abrir FIFO");
      
    }

    
    int factorial;
    if (read(fd, &factorial, sizeof(factorial)) == -1) {
        printf("lector: error al leer");
        close(fd);
      
    }

 
    printf("Número recibido: %d\n", factorial);
    if (factorial == 0)
    {
        printf("EL factorial de 0,  es 1 ");
    }
    
    printf("EL factorial de %d,  es %d \n", numero,factorial);

    unlink("pipe02");
    printf("Borrando PIPE");
    return 0;
    
   
}
