#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void main() {
    pid_t p2,p3;
    int fd[2];
    int fd2[2];
    int fd3[2];
    int fd4[2];
  
    pipe(fd);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);

    p2 = fork();


    if (p2 == 0) {
        int tamaño = 10;
        double notasRecibidas[tamaño];
        read(fd3[0], notasRecibidas , sizeof(notasRecibidas));
        double suma = 0;
        for(int i = 0 ; i < tamaño; i++){
            suma = suma + notasRecibidas[i];
        }

        double nota_media = (double) suma / tamaño;
        
        double nota_maxima = 0;

        for(int i = 0 ; i < tamaño; i++){
            if(notasRecibidas[i] > nota_maxima){
                 nota_maxima = notasRecibidas[i];     
                }
        }

        double notas[2] = {nota_media,nota_maxima};

        write(fd[1], &notas , sizeof(notas));
           printf("Termina p2 \n");

    }else {
        p3 = fork();
            if (p3 == 0) {
                 int tamaño = 10;
                 double notasRecibidas[tamaño];
                    read(fd4[0], notasRecibidas , sizeof(notasRecibidas));
                    int aprobado = 0;
                    int suspenso = 0;

                    for(int i = 0 ; i < tamaño; i++){
                        if(notasRecibidas[i] >= 5){
                            aprobado++;
                        }else{
                            suspenso++;
                        }
                    }
                int resultados[2] = {aprobado,suspenso};
                write(fd2[1], &resultados , sizeof(resultados));
                printf("Termina p3\n");
            } else{
        
        
        double notas[10];
        int contador = 0;
        
        printf("Soy P1 , dame las notas de 10 alumnos \n ");
            while (contador < 10) {
                printf("Nota %d: ", contador + 1);

                double nota_introducida;
                scanf("%lf", &nota_introducida);

                if (nota_introducida >= 0 && nota_introducida <= 10) {
                    notas[contador] = nota_introducida;
                    contador++;
                } else {
                    printf("Error. La nota debe estar entre 0 y 10.\n");
                }
        }
        
        write(fd3[1], notas , sizeof(notas));
        write(fd4[1], notas , sizeof(notas));

        double nota_media,nota_maxima;
        double notasP2[2] = {nota_media,nota_maxima};
        read(fd[0], &notasP2 , sizeof(notasP2));

        int aprobados,suspensos;
        int resultadosP3[2] = {aprobados,suspensos};
        read(fd2[0], &resultadosP3 , sizeof(resultadosP3));
        
        printf("P2 me ha mandado la media de las notas que es : %lf y me ha mandado la nota maxima que es : %lf  \n", notasP2[0],notasP2[1]);
        printf("P3 me ha mandado la cantidad de aprobados y es:  %d y me ha mandado la cantidad de suspensos, la cual es : %d \n ", resultadosP3[0],resultadosP3[1]);

            }
            waitpid(p2, NULL, 0);
            waitpid(p3, NULL, 0);
            printf("Termina p1\n");

        }   
    }
