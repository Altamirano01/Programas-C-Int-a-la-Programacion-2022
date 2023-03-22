//Algoritmo problema 4 practico 2
#include<stdio.h>
float peso;
float alimentoDiario;
void main(){
    printf("Ingrese el peso de su perro en Kg: ");
    scanf("%f", &peso);
        alimentoDiario = peso / 0.02;/!
    printf("El alimento que debe ingerir diariamente su perro de acuerdo a su peso es de: %fgr", alimentoDiario);
}