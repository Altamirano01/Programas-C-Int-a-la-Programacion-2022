//Algoritmo problema 7b practico 5
#include<stdio.h>
float n, pot;
float Cubo(float a){
    return(a * a * a);
}
void main(){
    printf("Ingrese un numero: ");
    scanf("%f", &n);
     pot = Cubo(n);
    printf("Se ha elevado %.2f al cubo, el resultado es: %.2f", n, pot); 
}