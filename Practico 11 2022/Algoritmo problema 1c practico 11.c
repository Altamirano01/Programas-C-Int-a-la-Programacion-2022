//Algoritmo problema 1c practico 11
#include<stdio.h>
int num;
int resultado;
//Devuelve la suma desde 1 hasta el numero ingresado
int sumatoria(int n){
  if(n == 1){
    return 1;
  }else if(n >= 2){
    return n + sumatoria(n - 1);
  }
}
void main(){
  printf("Ingrese un numero: ");
  scanf("%d", &num);
  resultado = sumatoria(num);
  printf("%d", resultado);
}