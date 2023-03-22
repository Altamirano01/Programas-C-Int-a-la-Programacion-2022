//Algoritmo problema 12 practico 3
#include<stdio.h>
float lado1, lado2, lado3;
char *mensaje;
void main(){
    printf("Ingrese el valor del lado 1 del triangulo: ");
    scanf("%f", &lado1);
    printf("Ingrese el valor del lado 2 del triangulo: ");
    scanf("%f", &lado2);
    printf("Ingrese el valor del lado 3 del triangulo: ");
    scanf("%f", &lado3);
        if(lado1 == lado2 && lado2 == lado3){//No se pude poner (lado1 == lado2 == lado3) porque no lo toma
            mensaje = "Equilatero";
        }else if((lado1 == lado2) && (lado2 != lado3) && (lado1 != lado3)){
            mensaje = "Isosceles";
        }else if((lado1 != lado2) && (lado2 != lado3) && (lado1 == lado3)){
            mensaje = "Isosceles";
        }else if((lado1 != lado2) && (lado2 == lado3) && (lado1 != lado3)){
            mensaje = "Isosceles";
        }else if((lado1 != lado2 && lado2 != lado3)){
            mensaje = "Escaleno";
        }        
    printf("El tipo de trialgulo es: %s", mensaje);
}