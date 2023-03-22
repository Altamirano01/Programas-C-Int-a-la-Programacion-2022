//Algoritmo problema 6 practico 7
#include<stdio.h>
#define Max 60
typedef struct{
    float a[Max];
    int cant;
}TData;
TData misVentas;
float suma;

void CargarVentas(TData *ventas){
    int i;
     printf("Ingrese la cantidad de ventas: ");
     scanf("%d", &ventas->cant);
     for(i = 0; i < ventas->cant; i++){
        printf("Ingrese una venta: ");
        scanf("%f", &ventas->a[i]);
    }
}
void Calcular(TData ventas, float *s){
    int i;
     *s = 0;
      for(i = 0; i < ventas.cant; i++){
        *s = *s + ventas.a[i];
      }
}
void main(){
    CargarVentas(&misVentas);
    Calcular(misVentas, &suma);
    printf("Se sumaron todas las ventas, el total es: %.3f", suma);
}
