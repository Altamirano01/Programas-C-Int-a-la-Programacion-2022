//Algoritmo areaBaldosa que resulve ejercicio 1 del practico 2
//Facundo Altamirano
#include<stdio.h>
float lado; // Datos
float supRayada; // Resultados
float areaCuad, supTriang; // Relaciones
void main(){
    printf("Ingrese el valor del lado a: ");
    scanf("%f", &lado);
      areaCuad = lado * lado;
      supTriang = ((lado / 2) * (lado / 2)) / 2;
      supRayada = areaCuad - supTriang;
      printf("La supercie rayada es igual a: %.3f", supRayada);
}