//Algoritmo problema 8 practico 4
#include<stdio.h>
int n, i, c, tabla;
void main(){
    printf("Ingrese que tabla quiere saber: ");
    scanf("%d", &n);
        i = 1;
        c = 1;
        printf("La tabla de %d es: ", n);
        while(i <= 10){
            tabla = n * c;
            printf("\n%d X %d = %d", n, c, tabla);
            i++;
            c++;
        }
}