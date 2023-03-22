//Algoritmo problema 2 practico 11
#include<stdio.h>
int num;
int res;
//Devuelve el numero en la posicion
int Fibonacci(int n);
void main(){
  printf("Ingrese la cantidad de numeros de la serie: ");
  scanf("%d", &num);
  res = 0;
  res = Fibonacci(num);
  printf("La suma es: %d", res);
}

int Fibonacci(int n){
  if((n == 1) || (n == 2)){
    return (1);
  }else if(n > 2){
    return (Fibonacci(n - 1) + Fibonacci(n - 2));
  }
}

