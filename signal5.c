#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>


void terminar2(int señal) {
  
    printf("Mandando señal de terminación al proceso hijo P2 con pid %d\n", getpid());
    exit(0);
}

void terminar3(int señal) {
  
    printf("Mandando señal de terminación al proceso hijo P3 con pid %d\n", getpid());
    exit(0);
}

int numero;

int main(){

   int fd[2];
  
    pipe(fd);

    pid_t pid2 = fork();

     if (pid2 == 0) {
        int numeroRecibido;
        close(fd[1]);
        signal(SIGTERM, terminar2);
       while (read(fd[0], &numeroRecibido, sizeof(numeroRecibido)) ) {
        printf("Número par %d recibido por el proceso P2 con pid %d\n",numeroRecibido,getpid() );
       }
       
     }else{

      pid_t pid3 = fork();

      if (pid3 == 0) {
          int numeroRecibido;
          close(fd[1]);
           signal(SIGTERM, terminar3);
          while (read(fd[0], &numeroRecibido, sizeof(numeroRecibido)) ) {
           printf("Número impar %d recibido por el proceso P3 con pid %d\n",numeroRecibido,getpid() );
          }
         
        }else{
          
      while (1){
      printf("Dame un número\n");
      scanf("%d", &numero);

        if(numero%2==0){
        write(fd[1], &numero, sizeof(numero));
      }

      if (numero%2!=0)
      {
        write(fd[1], &numero, sizeof(numero));
      }

      if (numero == 0) {
        kill(pid2, SIGTERM);
        kill(pid3, SIGTERM);
       break;
      }
    }    
    
    wait(NULL);
    wait(NULL);
    }
  }
}
    
    
    
    
