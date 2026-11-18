#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>

int contador = 5;

void tiempo(int señal){
 
  printf("Han transcurrido %d segundos\n" , contador);
  contador = contador +5;
  
  alarm(5);
  

}


int main(){

  signal(SIGALRM,tiempo); 
  alarm(5);
  while (1)
  {
     pause();
  }
  
 
}
