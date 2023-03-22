//Algoritmo problema 16 practico 3
#include<stdio.h>
#include<string.h>
float a, b ,c; //Coeficientes de la formula cuadratica
char mensaje[30];
float d;
void main(){
    printf("Ingrese el coeficiente a de la formula: ");
    scanf("%f", &a);
    printf("Ingrese el coeficiente b de la formula: ");
    scanf("%f", &b);   
    printf("Ingrese el coeficiente c de la formula: ");
    scanf("%f", &c);
        if(a == 0 && b == 0){
            strcpy(mensaje, "La Ecuacion es Degenerada");
        }else{
            strcpy(mensaje, "Tiene una raiz unica");
        }
        if(a != 0 && b != 0){
            d = b * b - 4 * a * c;
          if(d > 0){
              strcpy(mensaje, "Tiene 2 raices reales");
          }else if(d == 0){
              strcpy(mensaje, "Tiene 1 sola raiz");
          }else if(d < 0){
              strcpy(mensaje, "Tiene 2 raices complejas");
          }
        }      
    printf("%s", mensaje);
}//Creo que esta bien, deberia probarlo con mas numeros