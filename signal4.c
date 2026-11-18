#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>
#include <stdlib.h>


int veces; int segundos;

void alarma(int señal){

  
 
  for (size_t i = 0; i < veces; i++)
  {
    time_t hora;
  char *fecha ;
  time(&hora);
  fecha = ctime(&hora);
    printf("Señal de alarma recibida a las %s",fecha);
    sleep(segundos);
  }
}


int main(){

  printf("cuantas veces sonara la alarma\n");
  scanf("%d", &veces);

  printf("Cada cuanto segundos\n");
  scanf("%d", &segundos);

  signal(SIGALRM,alarma); 
  alarm(1);
  pause();
  
  
}
