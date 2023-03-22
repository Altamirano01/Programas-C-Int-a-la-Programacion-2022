//Algoritmo problema 11 practico 4
#include<stdio.h>
#include<string.h>
char mensaje[60];
int n, num, i;
void main(){
    printf("Ingrese el numero hasta el que quiere saber divisores de 2, 4 y 6: ");
    scanf("%d", &n);
        num = 1;
        for(i == 1; i < n; i++){
            if((num % 2 == 0) && (num % 4 == 0) && (num % 6 == 0)){
                strcpy(mensaje, "es divisor de 2, 4 y 6.");      
        }else{
                strcpy(mensaje, "No es divisible por 2, 4 y 6 simultaneamente.");
        }
        printf("El numero: %d %s\n", num, mensaje);
        num++;
        }
}//Ver como hacer para que el usuario ingrese la cantidad de divisores que quiera