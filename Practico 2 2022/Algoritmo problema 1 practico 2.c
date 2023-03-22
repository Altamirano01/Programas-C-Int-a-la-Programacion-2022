//Algoritmo practico 2 ejercicio 1
#include<stdio.h>
float a; // Datos
float supCuad, supRayada, supTriang; // Resultados y relaciones
void main(){
    printf("Ingrese el valor del lado a: ");
    scanf("%f", &a);
      supCuad = a * a;
      supTriang = ((a / 2) * (a / 2)) / 2;
      supRayada = supCuad - supTriang;
      printf("\nLa supercie rayada es igual a: %f", supRayada);
}
//Comentario normal
//! Advertencia
///// Borrar
//all General
//? Pregunta
//*algo