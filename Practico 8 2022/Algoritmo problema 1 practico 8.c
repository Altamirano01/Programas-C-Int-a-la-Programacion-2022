//Algoritmo problema 1 practico 8
#include<stdio.h>

#define M 200//Numero maximo de espacios para el arreglo

typedef struct TPersona{
  char apellido [60];
  int dni;
}TPersona;//Registro

typedef struct TData{
  struct TPersona a[M];
  int cant;
}TData;//TData con arreglo

struct TData persona;
int doc;//Variables
 
void Cargar(struct TData *q){
 int i;
  printf("\nINGRESE LA CANTIDAD DE APELLIDOS A CARGAR: ");
  scanf("%d", &q->cant);
  for(i = 0; i < q->cant;i++){
    printf("Ingrese un apellido: ");
    scanf("%s", &q->a[i].apellido);
    printf("Ingrese el DNI: ");
    scanf("%d", &q->a[i].dni);
  }
}//Accion para cargar el arreglo

void Buscar(struct TData q, int d){
 int i;
  for(i = 0; i < q.cant; i++){
    if(q.a[i].dni == d){
      printf("\nAPELLIDO ENCONTRADO.\n");
      printf("-%s\n", q.a[i].apellido);
  }
  if(i >= q.cant){//El ciclo termino sin encontrar el dni en la lista
    printf("\nAPELLIDO INEXISTENTE.\n");//!Ver esto, porque siempre imprime el que no encontro el apellido
                                        //!Debo ver como agregar un Break
  }
}//Accion para buscar un apellido segun el dni

void Mostrar(struct TData q){
 int i;
 printf("\n\tLISTADO\n");
 printf("\n");
  for(i = 0; i < q.cant; i++){
    printf("Documento: %d\tApellido: %s\n", q.a[i].dni, q.a[i].apellido);
  }
}//Accion para mostrar la lista de apellidos

int main(){
  //Hay que hacer un menu adecuado para que quede mas prolijo
  Cargar(&persona);
   printf("INGRESE EL DNI DE LA PERSONA DE LA LISTA: ");
   scanf("%d", &doc);
  Buscar(persona, doc);
  Mostrar(persona);
  return(0);
}