//Algoritmo problema 1 practico 12
#include<stdio.h>
#include<string.h>

#define M 200
typedef char Cadena[200];
typedef struct TElem{
  Cadena ISBM;
  Cadena apellido;
  Cadena titulo;
}TElem;

Cadena aux;

typedef struct TData{
  TElem a[M];
  int cant;
}TData;

TData arreglo;

void Cargar(TData *q){
  int i;
  printf("Cant elem arreglo: ");
  scanf("%d", &q->cant);
  for(i = 0; i < q->cant; i++){
    printf("Ingrese el autor: ");
    scanf("%s", q->a[i].apellido);
    printf("Ingrese el titulo: ");
    scanf("%s", q->a[i].titulo);
  }

}
// TIENE QUE ESTAR ODERNADO
// Accion para buscar el titulo de un libro de un autor
//! Ver por que no funciona con cadenas, pero si anda con enteros xd
void Busqueda(TData s, Cadena e){
  int i;
    i = 0;
    while(i < s.cant && s.a[i].apellido < e){
      i++;
    }
    if(i < s.cant){
      if(strcmp(s.a[i].apellido, e) == 0){
        printf("\nTitulo: %s", s.a[i].titulo);
        //! No imprime el titulo si esta en la posicion mayor a cero
      }else{
        printf("No se encontro al autor.\n");
      }
    }else{
      printf("Arreglo vacio.\n");
    }
}

void main(){
  Cargar(&arreglo);
  printf("Ingrese el apellido del autor a buscar: ");
  scanf("%s", aux);
  Busqueda(arreglo, aux);
}