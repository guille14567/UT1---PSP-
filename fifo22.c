#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {

    const char *pipe02 = "pipe02";
    
    int numRecibido;

    mkfifo(pipe02, 0666);


    printf("Esperando número del escritor...\n");

    
    int fd = open(pipe02, O_RDONLY);
    if (fd == -1) {
        printf("IMposible abrir FIFO");
        
    }

    // Leer el número enviado
    if (read(fd, &numRecibido, sizeof(numRecibido)) == -1) {
        printf("lector: error al leer");
        close(fd);
       
    }

    printf("Número recibido: %d\n", numRecibido);
    printf("Calculando facotorial y mandadno a fifo11...\n");
        for (int i = numRecibido - 1; i>0;i--){
            numRecibido = numRecibido * i;
    }
    

    fd = open(pipe02, O_WRONLY);
    if (fd == -1) {
        printf("escritor: error al abrir FIFO \n");
      
    }

    // Escribir el número en la FIFO
    if (write(fd, &numRecibido, sizeof(numRecibido)) == -1) {
        printf("escritor: error al escribir\n");
    } else {
        printf(" Número %d enviado al lector.\n", numRecibido);
    }

    close(fd);
    return 0;
}
