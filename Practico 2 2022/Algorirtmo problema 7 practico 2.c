//Algoritmo problema 7 practico 2
#include<stdio.h>
int a, b;
void main(){
    printf("Ingrese un numero A: ");
    scanf("%d", &a);
    printf("Ingrese otro numero B: ");
    scanf("%d", &b);//Ingreso de datos
        a = a + b;
        b = a - b;
        a = a - b;//Swap
    printf("Los numeros han sido intercambiados. ");
    printf("\nLos nuevos valores de los numeros son: A:%d  B:%d", a, b);//Salida de datos
}//Ver como poder hacer para que el programa se rompa cuando se ingresa cualquier otro tipo de numero que no sea entero
//Probablemente con un if mod da 0