//Algoritmo problema 3 practico 12
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
     printf("Ingrese la cantidad de elementos: ");
     scanf("%d", &q->cant);
     printf("\nLOS NUMEROS DEBEN ESTAR ORDENADOS\n\n");
     for(i = 0; i < q->cant; i++){
        printf("Ingrese una numero: ");
        scanf("%d", &q->a[i]);
    }
}

void BusquedaBinaria(TData q, int e){
  int i, inf, sup;
    if((e < q.a[0]) || (e > q.a[q.cant])){
      printf("EL ELEMENTO NO ESTA EN EL ARREGLO\n");
    }else if((q.a[0] <= e) && (e <= q.a[q.cant])){
      inf = 0;
      sup = q.cant;
      while(inf <= sup){
        i = (inf + sup) / 2;
        if(e > q.a[i]){
          inf = i + 1;
        }else if(e <= q.a[i]){
          sup = i;
        }
      }
      if(q.a[inf] == e){
        printf("Pos: %d", i);
      }else{
        printf("No esta.");
      }
    }
}

void main(){
  Cargar(&arreglo);
  elemento = 4;
  printf("BUSQUEDA DE %d\n", elemento);
  BusquedaBinaria(arreglo, elemento);
}
