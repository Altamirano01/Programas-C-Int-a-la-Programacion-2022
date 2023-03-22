//Algoritmo problema 1 practico 3
#include<stdio.h>
int edad;
char *mensaje;
void main(){
    printf("Ingrese la edad: ");
    scanf("%d", &edad);
    if(edad >= 0){
        if(edad >= 18){
            mensaje = "Eres mayor de edad";
        }else{
            mensaje = "Eres menor de edad";
        }
    }else{
        printf("ERROR! Edad Invalida.");
    }
    printf("%s", mensaje);
}//Ver como hacer para que el programa se rompa cuando se ingresa un numero real