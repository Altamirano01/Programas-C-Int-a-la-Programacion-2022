//Algoritmo problema 8 practico 4
#include<stdio.h>
#include<string.h>
float notas,sumaNotas, promedio;
int alumnos, i;
char mensaje[20];
void main(){
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnos);
        printf("A continuacion ingrese las notas en orden lista y con dos decimales despues de la coma en caso de ser necesario:\n");
        sumaNotas = 0;
        for(i == 1; i < alumnos; i++){
            printf("-");
            scanf("%f", &notas);
            sumaNotas = sumaNotas + notas;
        }
        promedio = sumaNotas / alumnos;
        if(promedio >= 8){
            strcpy(mensaje, "Elevado");
        }else if(6 <= promedio && promedio < 8){
            strcpy(mensaje, "Aceptable");
        }else if(promedio < 6){
            strcpy(mensaje, "Bajo");
        }
    printf("El promedio general del curso ha sido %s", mensaje);
}
