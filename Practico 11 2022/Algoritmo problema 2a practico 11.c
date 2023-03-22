//Algoritmo problema 2a practico 11
#include<stdio.h>
#define M 200
typedef struct TData{
  int a[M];
  int cant;
}TData;
TData arreglo;
int suma;
void Suma(TData q, int *s){
  s = 0;
  if(q.cant == 0){
    s = s + 0;
  }else if(0 < q.cant && q.cant <= 30){
    s = s + q.a[q.cant];
    q.cant--;
    Suma(q, s);
  }
}
void main(){
  printf("Ingrese ")
}