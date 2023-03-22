//Algoritmo problema 8 practico 7
#include<stdio.h>
#define NMax 200
typedef struct{
    int n[NMax];
    int cant;
}TData;
TData notas;
float promedio;
float aprobados;
float reprobados;
void Cargar(TData *q, float *a, float *r){//Accion que carga las notas y suma la cantidad de aprobados y reprobados
     int i;
    printf("Ingrese la cantidad de notas a cargar: ");
    scanf("%d", &q->cant);
      *a = 0;
      *r = 0;
      for(i = 0; i < (*q).cant; i++){//Ver por que no me carga las notas
          printf("Ingrese una nota: ");
          scanf("%d", &q->n[i]);
          if(5 <= q->n[i]){
              *a = *a + 1;
          }else{
              *r = *r + 1;
          }
      }
} 
void Promedio(TData q, float *prom){//Accion que saca el promedio
    int i;
    float sum;
     sum = 0;
     *prom = 0;
     for(i = 0; i < q.cant; i++){
         sum = sum + q.n[i];
     }
     *prom = sum / q.cant;
}
void Mostrar(TData q, float prom, float a, float r){//Accion que muestra el promedio, la cantidad de aprobados y reprobados y el porcentaje de c/u.
 int i;
 printf("Las notas cargadas son: ");
 for(i = 0; i < q.cant; i++){
  printf("%d - ", q.n[i]);
 }
 printf("\nEl promedio de los alumnos fue de: %.3f\n", prom);
 printf("La cantidad de alumnos que aprobaron fue de: %.1f\n", a);
 printf("La cantidad de alumnos que reprobaron fue de: %.1f\n", r);
 a = a * 100 / q.cant;
 r = r * 100 / q.cant;
 printf("El porcentaje de alumnos que aprobo es: %.2f\n", a);
 printf("El porcentaje de alumnos que reprobo es: %.2f\n", r);
}
void main(){
    Cargar(&notas, &aprobados, &reprobados);
    Promedio(notas, &promedio);
    Mostrar(notas, promedio, aprobados, reprobados);
}          