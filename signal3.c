#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>
#include <stdlib.h>




void parar(int señal){
 
     time_t hora;
  char *fecha ;
  time(&hora);
  fecha = ctime(&hora);

   FILE *fichero = fopen("salidas.txt", "a");

    fprintf(fichero, "Señal SIGINT recibida a las %s\n", fecha);

    fclose(fichero);

    
 
}


int main(){

  while (1)
  {
    signal(SIGINT,parar); 
    pause();
  }

  

}
