//Algoritmo problema 7a practico 5
#include<stdio.h>
int x, incremento;//Datos y resultados
int Inc(int a){
   return(a + 1); 
}//Funcion
void main(){
    printf("Ingrese un numero: ");
    scanf("%d", &x);
     incremento = Inc(x);
    printf("El numero incrementado es: %d", incremento);
}