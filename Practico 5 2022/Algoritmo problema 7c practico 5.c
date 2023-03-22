//Algoritmo problema 7c practico 5
#include<stdio.h>
int x;
int res;
//No existe el tipo logico en lenguaje c, por lo que tengo que retornar 0 o 1 para expresar V o F
int Par(int a){
    if(a % 2 == 0){
        return(1);
    }else{
        return(0);
    }
}
void main(){
    printf("Ingrese un numero: ");
    scanf("%d", &x);
     res = Par(x);
    printf("Si el numero es par entonces el valor es 0 sino el valor es 1. El valor es: %d", res);
}   