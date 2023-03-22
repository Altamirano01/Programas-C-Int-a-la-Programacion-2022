//Algoritmo problema 3 practico 4
#include<stdio.h>
#include<string.h>
char letra[2];
char mensaje[25];
void main(){
    do{
        printf("Ingrese la letra: ");
        strcpy(mensaje, "Desea continuar S/N: ");
        printf("%s", mensaje);
        fgets(letra, 2, stdin);
    }while(letra == "N");
}//No se como se hace 