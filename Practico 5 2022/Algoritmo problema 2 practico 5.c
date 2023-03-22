//Algoritmo problema 2 practico 4
#include<stdio.h>
#include<math.h>
float lado;
float ladoA, ladoB;
float circunscripto, inscripto, perimCirc;
float areaCirc(float r){
    float l;
    l = 3,14 * r * r;
    return(l);
}//Funcion area circulo

float longCirc(float r){
    float l1;
    l1 = 2 * 3,14 * r;
    return(l1);
}//Funcion perimetro de un circulo

void main(){
    printf("Ingrese el lado del cuadrado: ");
    scanf("%f", &lado);
        ladoA = lado / 2;
        ladoB = lado * (sqrt(2)) / 2;
        inscripto = areaCirc(ladoA);
        circunscripto = areaCirc(ladoB);
        perimCirc = longCirc(ladoB);
    printf("El area del circulo inscripto es: %.3f\n", inscripto);
    printf("El area del circulo circunscripto es: %.3f\n", circunscripto);   
    printf("El perimetro del circulo circunscripto es: %.3f\n", perimCirc);
}
//Ver si puedo poner como argumento al invocar una funcion una operacion o tengo q poner directamente el lado ya dividido por 2