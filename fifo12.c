#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {

    const char *fifo = "canal_num";
    const char *fifo2 = "canal_num";
    int numeroRecibido;

    // Crear FIFO si no existe
    mkfifo(fifo, 0666);
    mkfifo(fifo2, 0666);

    printf("Esperando número del escritor...\n");

    // Abrir FIFO para lectura (bloquea hasta que el escritor escriba)
    int fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        printf("lector: error al abrir FIFO");
        
    }

    // Leer el número enviado
    if (read(fd, &numeroRecibido, sizeof(numeroRecibido)) == -1) {
        printf("lector: error al leer");
        close(fd);
       
    }

    printf("Número recibido: %d\n", numeroRecibido);
    printf("Calculando facotorial y mandadno a fifo11...\n");
        for (int i = numeroRecibido - 1; i>0;i--){
            numeroRecibido = numeroRecibido * i;
    }
    

    int fd2 = open(fifo2, O_WRONLY);
    if (fd2 == -1) {
        printf("escritor: error al abrir FIFO\n");
      
    }

    // Escribir el número en la FIFO
    if (write(fd2, &numeroRecibido, sizeof(numeroRecibido)) == -1) {
        printf("escritor: error al escribir\n");
    } else {
        printf(" Número %d enviado al lector.\n", numeroRecibido);
    }

    close(fd2);
    return 0;
}
