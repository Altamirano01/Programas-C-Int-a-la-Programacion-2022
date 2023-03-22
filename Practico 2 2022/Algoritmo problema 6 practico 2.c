//Algoritmo ejercicio 6 practico 6
#include<stdio.h>
int a, b;
int resto, cociente;
void main(){
    printf("Ingrese el dividendo: ");
    scanf("%d", &a);
    printf("Ingrese el divisor: ");
    scanf("%d", &b);//Entrada de datos
    resto = (a / b); // DIV = /
    cociente = (a % b);// MOD = %
    printf("\nEl cociente de la division es de: %d", resto);
    printf("\nEl resto de la division es de: %d", cociente);   
}