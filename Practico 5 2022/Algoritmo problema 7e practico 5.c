//Algoritmo problema 7e practico 5
#include<stdio.h>
int a, x;
float pot;
float Potencia(int b, int y){
    int i;
    float aux;
    aux = 1;
     for(i == 1; i < y ; i++){
         aux = aux * b;
     }
    return(aux);//Tengo que ver donde va este, porque siempre me retorna 1, que es el valor que tiene aux por defecto
}
void main(){
    printf("Ingrese la base: ");
    scanf("%d", &a);
    printf("Ingrese el exponente: ");
    scanf("%d", &x);
     pot = Potencia(a, x);
    printf("%f", pot);
}