printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
if (pid == 0) {
 printf("Soy el hijo\n");
} else {
 printf("Soy el padre\n");
}
printf("Fin\n");


a) ¿Cuántos procesos existen?
Existen 2 procesos, uno padre y uno hijo.

b) ¿ qué instrucciones ejecuta cada uno?

El padre ejecuta: printf("Inicio\n");  printf("Después del fork\n");  printf("Soy el padre\n"); printf("Fin\n");
El hijo en cambio ejecuta:  printf("Después del fork\n");  printf("Soy el hijo\n"); printf("Fin\n");

c) ¿cuántas veces aparece cada mensaje y qué partes de la salida pueden aparecer en distinto
orden?
printf("Inicio\n"); - 1 VEZ

printf("Después del fork\n"); - 2 VECES

 printf("Soy el hijo\n"); - 1 VEZ

 printf("Soy el padre\n"); - 1 VEZ

printf("Fin\n"); 2 VECES

La parte de la salida que puede aparecer en distitno orden es una vez se entra al if, ya que al ser aleatorio puede elegir ejecutarse primero el padre y después el hijo, o a la inversa.
