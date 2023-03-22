//Algoritmo problema 7 practico 7
#include<stdio.h>
#include<time.h>
#include<stdlib.h>//Estas bibliotecas sirven para usar la accion random
#define Max 200
typedef struct{
    int a[Max];
    int cant;
}TData;
TData loteria;
 void Loteria(TData *q){
  int i;
 q->cant = 30;
 srand(time(NULL));//Inicializa la funcion rand
  for(i = 0; i < q->cant; i++){
    //Si pongo la inicializacion aca no me anda
      q->a[i] = rand() % (1000 - 0) + 0;//La funcion rand es asi: rand() % (limite superior + 1 - limite inferior) + limite inferior
  }
}
void Mostrar(TData q){
    int i;
    printf("Se ha realizado el sorteo, los numeros sorteados son: ");
    for(i = 0; i < q.cant; i++){
        printf("\n-%d", q.a[i]);
    }
}
void main(){
    Loteria(&loteria);
    Mostrar(loteria);
}