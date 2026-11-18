
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>




void fechayHoraFin(int señal){
 
   time_t hora;
  char *fecha ;
  time(&hora);
  fecha = ctime(&hora);

  printf("Fecha y hora de finalizacion %s del proceso : %d\n", fecha,getpid());




  
}


int main(){

  time_t hora;
  char *fecha ;
  time(&hora);
  fecha = ctime(&hora);

  printf("Fecha y hora de inicio %s del proceso : %d\n", fecha,getpid());


  signal(SIGINT,fechayHoraFin); 

  pause();
}
