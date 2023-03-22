//Algoritmo problema 5 practico 7
#include<stdio.h>
#define N 200
typedef struct{
    float n[N];
    int cant;
}TNotas;
TNotas misNotas;
float promedio;
//! Aca guarde sin querer y se borraron cosas
void CargarNotas(TData *q){
    int i;
     printf("Ingrese la cantidad de notas: ");
     scanf("%d", &q->cant);
     for(i = 0; i < q->cant; i++){
        printf("Ingrese una nota: ");
        scanf("%d", &q->a[i]);
    }
}


void PromedioNotas(TNotas notas, float *p){
    int i;
    float suma;
     suma = 0;
     *p = 0;
      for(i = 0; i < notas.cant; i++){
        suma = suma + notas.n[i];
      }
      *p = suma / notas.cant;
}

void main(){
    CargarNotas(&misNotas);
    PromedioNotas(misNotas, &promedio);
     printf("Se ha calculado el promedio gral.: ");
     printf("El promedio es: %.3f ", promedio);
}