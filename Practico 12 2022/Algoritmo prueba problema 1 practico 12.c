// Algoritmo problema 1 practico 12 Con enteros
//Algoritmo problema 1 practico 12
#include<stdio.h>

#define M 200
typedef struct TData{
  int a[M];
  int cant;
}TData;
TData arreglo;
int elemento;

void Cargar(TData *q){
  int i;
  printf("Cant elem arreglo: ");
  scanf("%d", &q->cant);
  for(i = 0; i < q->cant; i++){
    printf("Ingrese un numero: ");
    scanf("%d", &q->a[i]);
  }
}
// TIENE QUE ESTAR ODERNADO
// Accion para buscar un numero del arreglo
void Busqueda(TData s, int e){
  int i;
    i = 0;
    while(i < s.cant && s.a[i] < e){
      i++;
    }
    if(i < s.cant){
      if(s.a[i] == e){
        printf("\n#Posicion#: %d", i);
        //! No imprime el titulo si esta en la posicion mayor a cero
      }else{
        printf("NUMERO NO ENCONTRADO.\n");
      }
    }else{
      printf("vACIo.\n");
    }
}

void main(){
  Cargar(&arreglo);
  printf("Ingrese el numero a buscar: ");
  scanf("%d", &elemento);
  Busqueda(arreglo, elemento);
}