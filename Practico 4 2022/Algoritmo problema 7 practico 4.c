//Algoritmo problema 7 practico 4
#include<stdio.h>
int n, num, i, suma;
void main(){
    printf("Ingrese la cantidad de numeros a sumar: ");
    scanf("%d", &n);
        num = 1;
        suma = 0;
        i = 1;
        while(i <= n){
            suma = suma + num;
            num = num + 1;
            i = i + 1;
        }
    printf("La suma de %d numeros es: %d", n, suma);
}