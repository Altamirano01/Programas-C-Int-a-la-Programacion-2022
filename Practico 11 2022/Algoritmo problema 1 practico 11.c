//Algoritmo problema 1 practico 11
#include<stdio.h>
int base, exponente;
int resultado;
int Potencia(int b, int e){
  if(e == 0){
    return(1);
  }else if(e == 1){
    return(b);
  }else if(e > 1){
    return (b * Potencia(b, e - 1));
  }
}
void main(){
  printf("Ingrese la base: ");
  scanf("%d", &base);
  printf("Ingrese el exponente: ");
  scanf("%d", &exponente);
  resultado = Potencia(base, exponente);
  printf("%d", resultado);
}