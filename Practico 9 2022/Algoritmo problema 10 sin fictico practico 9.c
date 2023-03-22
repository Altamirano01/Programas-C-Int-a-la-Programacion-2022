//Algoritmo problema 10 sin fictico practico 9.c
#include<stdio.h>
#include<stdlib.h>
typedef struct TNodo{
  int info;
  struct TNodo *next, *back;//Un puntero para saber el siguiente y el anterior
}TNodo;
struct TNodo *q, *r;//Un puntero que apunte al primero y otro al ultimo
int posicion;//Contador pasa saber la posicion en la que quiero insertar
int menu;

void Inicializar(struct TNodo **m, struct TNodo **a){
  *m = NULL;
  *a = NULL;
}

void Cargar(struct TNodo **m, struct TNodo **a){
  struct TNodo *aux, *s;
  aux = *m;
  s = *m;
  if(aux == NULL){
    //Insercion a la cabeza
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->next = NULL;
    aux->back = NULL;
    *m = aux;
    *a = aux;
  }else{
    //Insercion al final
    //Busco el final
    while(s->next != NULL){
      s = s->next;
    }
    //Hago la insercion
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->back = s;
    aux->next = s->next;
    s->next = aux;
    *a = aux;//Por que es el nuevo ultimo
  }
}

void InsertarPos(struct TNodo **m, struct TNodo **a, int pos){
  struct TNodo *aux, *s;
  int i;
    s = *m;
    aux = *m;
    i = 0;
    if(aux != NULL){
      while(s->next != NULL){
      s = s->next;
      }
      if(i == pos){
        //Insercion normal
        aux = (TNodo *) malloc(sizeof(struct TNodo *));
        printf("Ingrese un numero: ");
        scanf("%d", &aux->info);
        aux->back = s;
        aux->next = s->next;
        s->next->back = aux;
        s->next = aux;
        s->next = aux;
      }else{
        printf("POSICION NO ENCONTRADA.\n");
      }
    }else{
      //Insertar a la cabeza
      aux = (TNodo *) malloc(sizeof(struct TNodo *));
      printf("Ingrese un numero: ");
      scanf("%d", &aux->info);
      aux->back = NULL;
      aux->next = NULL;
      *m = aux;
      *a = aux; 
    }
}

void Mostrar(struct TNodo *m, struct TNodo *a){
  struct TNodo *aux;
  aux = m;
  //!Agregar que pasa cuando la lista esta vacia
  printf("\n\tLISTADO:\n ");
  while(aux != NULL){
    printf(" %d", aux->info);
    aux = aux->next;
  }
  printf("\n");
}

void main(){
  menu = 0;
  //El menu no se corta con numeros distintos a los que debe ingresar el usuario, por eso hay que usar un switch
  do{
    printf("\n\tMENU\n");
    printf("1| Inicializar.\n");
    printf("2| Cargar un elemento.\n");
    printf("3| Insertar en una posicion.\n");
    printf("4| Mostrar lista.\n");
    printf("5| Salir.\n");
    printf("\nINGRESE EL NUMERO DE OPERACON QUE DESEE REALIZAR: ");
    scanf("%d", &menu);
    if(menu == 1){
      Inicializar(&q, &r);
      menu = 0;
    }else if(menu == 2){
      Cargar(&q, &r);
      menu = 0;
    }else if(menu == 3){
      printf("Ingrese la posicion: ");
      //La primera posicion es el cero
      scanf("%d", &posicion);
      InsertarPos(&q, &r, posicion);
      menu = 0;
    }else if(menu == 4){
      Mostrar(q, r);
    }else if(menu == 5){
      printf("\nCERRANDO PROGRAMA.\n");
    }
  }while(menu != 5);
}