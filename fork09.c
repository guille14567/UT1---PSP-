#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
  pid_t p2, p3,p4;

  p2 = fork();
  
  if (p2 == 0){
    printf("Soy p2, Me duermo 5 segundos \n");
    sleep(5);
    printf("Soy p2, ya he despertado\n");
  }else{
    p3 = fork();
        if (p3 == 0){
   
        printf("Soy p3, Me duermo 2 segundos\n");
        sleep(2);
        printf("Soy p3, ya he despertado\n");
        }else{
        p4 = fork();
        if (p4 == 0){
       
        printf("Soy p4, Me duermo 4 segundos\n");
        sleep(4);
        printf("Soy p4, ya he despertado\n");
    }
  }
}
    wait(NULL);
    wait(NULL);
    wait(NULL);
}

a) ¿Podemos asegurar ahora qué proceso terminará primero?

Sí, simepre va a terminar primero p3 porque es el que menos duerme y no tiene que esperar a ningún proceso para ejecutarse ni terminar.
  
b) Si eliminamos la instrucción sleep() ¿cuál sería el orden de terminación?

Soy p2, Me duermo 5 segundos 
Soy p3, Me duermo 2 segundos
Soy p2, ya he despertado
Soy p3, ya he despertado
Soy p4, Me duermo 4 segundos
Soy p4, ya he despertado


Al no tener la orden sleep(), el orden de terminación sería por ejecucción, ya que no entra a p4 si no ha terminado ambos anteriores.





