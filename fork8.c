a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo que el pid del programa fork8 es el 1000 
  y los pids se generan de uno en uno en orden creciente
      P1 (PID: 1000)
      ├──→ P2 (PID 1: 1001)
      └──→ P3 (PID 2 : 1002)
b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta 
AAA
CCC
BBB
CCC

AAA
BBB
CCC
CCC

  
Este código puede tener estas salidas, ya que al ser un orden aleatorio de ejecución puede hacer primero pid1 o que se ejecute primero el padre.

c) Añade el código necesario para que el orden de ejecución sea tal que los respectivos procesos padre sean los últimos que se ejecuten. 


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid1, pid2;
printf("AAA \n");
pid1 = fork();
if (pid1==0)
{
printf("BBB \n");
}
else
{
pid2 = fork();
if(pid2==0){
printf("CCC \n");
}else{
   waitpid(pid1,NULL,0);
   waitpid(pid2,NULL,0);
   printf("CCC \n");
}
exit(0);
}
}
