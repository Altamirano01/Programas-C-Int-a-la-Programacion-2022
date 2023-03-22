//Algoritmo problema 6 practico 3
#include<stdio.h>
int diasVuelo;
int cantPasajes;// Datos
float precioPasaje;// Resultados
void main(){
    printf("Ingrese la cantidad de pasajes que desea comprar: ");
    scanf("%d", &cantPasajes);
    printf("Ingrese la cantidad de dias que restan para la fecha de salida del vuelo: ");
    scanf("%d", &diasVuelo);
        if(diasVuelo >= 30){
            precioPasaje = cantPasajes * 4650;
        }else if(15 <= diasVuelo < 30){
            precioPasaje = cantPasajes * 5350;
        }else if(1 <= diasVuelo < 15){
            precioPasaje = cantPasajes * 6875;
        }else if(diasVuelo < 1){
        printf("ERROR! No se puede pedir pasajes para esa fecha.");    
        }
    printf("El precio total por %d pasajes es de: $%.3f", cantPasajes, precioPasaje);
}