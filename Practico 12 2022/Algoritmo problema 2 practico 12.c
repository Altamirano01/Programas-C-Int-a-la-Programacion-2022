// Algoritmo problema 2 practico 12
#include<stdio.h>
#define M 200
typedef struct TData{
  int a[M];
  int cant;
}TData;
TData arreglo;
int i, posicion, k;

void Cargar(TData *q){
    int i;
     printf("Ingrese la cantidad de elementos: ");
     scanf("%d", &q->cant);
     for(i = 0; i < q->cant; i++){
        printf("Ingrese una numero: ");
        scanf("%d", &q->a[i]);
    }
}

int SecuencialRecursiva(TData q, int k, int *pos, int i){
  if(i < 0){
    return(0);
  }else if(i >= 0){
    if(q.a[i] == k){
      *pos = i;
      i = -1;
      SecuencialRecursiva(q, k, pos, i);
    }else{
      i--;
      SecuencialRecursiva(q, k, pos, i);
    }
  }
}

void main(){
  Cargar(&arreglo);
  i = arreglo.cant;
  k = 1;// Es el que quiero buscar, lo puedo ingresar con una entrada
  posicion = 0;
  SecuencialRecursiva(arreglo, k, &posicion, i);
    printf("Posicion: %d", posicion);
}