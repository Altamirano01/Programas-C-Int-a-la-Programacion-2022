//Algoritmo problema 13 practico 4
#include<stdio.h>
float a, y;//Datos
float pot;//Resultado
int i;//Auxiliar
void main(){
    printf("Ingrese la base: ");
    scanf("%f", &a);
    printf("Ingrese el exponente: ");
    scanf("%f", &y);
    pot = 1;
        for(i == 1; i < y; i++){
            pot = pot * a;
        }
    printf("%.2f elevado a %.2f es igual a %.2f", a, y, pot);    
}//Ver como hacer para que abarque tambien los numeros negativos