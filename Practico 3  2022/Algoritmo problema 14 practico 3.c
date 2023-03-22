//Algoritmo problema 14 practico 3
#include<stdio.h>
float horas;
float salario;
void main(){
    printf("Ingrese la cantidad de horas trabajadas en la ultima semana: ");
    scanf("%f", &horas);
        if(horas <= 40){
            salario = horas * 10;
        }else if(horas > 40){
            salario = horas * 10 - (horas - 40 * 15);
        }
    printf("El salario correspondiente a %.3f horas trabajadas es: %.3f", horas, salario);    
}