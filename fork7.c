a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo
que el pid del programa fork7 es el 1000 y los pids se generan de uno en uno en orden creciente.

P1 (PID: 1000)
├──→ P2 (PID: 1001)

El padre crea un proceso hijo.
  
b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta

CCC 
AAA 
BBB 

El código genera esta salida. Siempre y todas las veces que se ejecute. No puede haber otra salida de código porque CCC siempre se imprime primero, como solo hay un proceso hijo y el if indica que entra si es distinto de 0, nunca ejecutara antes el hijo.

c) Modificar el código para que la salida por pantalla sea:
CCC
BBB
AAA

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void main()
{
 printf("CCC \n");
if (fork()==0)
    {
        printf("AAA \n");
  } else printf("BBB \n");
  
 exit(0);
}
