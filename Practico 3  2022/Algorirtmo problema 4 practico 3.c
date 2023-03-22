//Algoritmo problema 4 practico 3
#include<stdio.h>
float distancia;
float montoPagar;
void main(){
    printf("Ingrese la cantidad de Km recorridos: ");
    scanf("%f", &distancia);
        if(distancia >= 0){ //Agrege un if asi se rompe el programa si ingresa distancia negativa
        if(distancia <= 300){
            montoPagar = distancia * 30;
        }else if(300 < distancia <= 1000){
            montoPagar = (distancia * 30) + (distancia * 0.75 - 300);
        }else if(distancia > 1000){
            montoPagar = (distancia * 30) + (distancia * 0.75 - 300) + (distancia * 0.5 - 1000);
        }
        printf("\nEl monto total a pagar por %.3fKm recorridos es de: $%.3f", distancia, montoPagar);//Se agrega %.3f para que solo saque 3 decimales despues de la coma
        }else{
            printf("ERROR! La distancia no puede ser negativa.");
        }
}