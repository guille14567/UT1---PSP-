#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main() {
    int fd[2];
  
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);
        time_t hora;
        char *fecha;
        time(&hora);
        fecha = ctime(&hora) ;
          
        read(fd[1], fecha, sizeof(fecha));

        printf("Soy el proceso hijo con pid %d \n" , getpid());
        printf("HIJO: He recibido que estamos a %s\n", fecha);
        
        close(fd[0]);
        printf("HIJO ha terminado \n");

    }
    else {
        // PADRE: solo escribe
        close(fd[0]);
        time_t hora;
        char *fecha ;
        time(&hora);
        fecha = ctime(&hora) ;

          
        write(fd[1], fecha, sizeof(fecha));

        close(fd[1]); 
        wait(NULL);
        printf("PADRE ha terminado \n");

    }


}
