//Algoritmo problema 18 practico 3
#include<stdio.h>
#include<string.h>
int year;
char mensaje[20];
void main(){
    printf("Ingrese un año: ");
    scanf("%d", &year);
        if((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
            strcpy(mensaje, "Bisiesto");
        }else{
            strcpy(mensaje, "No Bisiesto");
        }
        
    printf("El año %d es: %s", year, mensaje);             
}
