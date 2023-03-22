//Algoritmo problema 10 practico 9 sin elemento ficticio
#include<stdio.h>
#include<stdlib.h>
typedef struct TNodo{
  int info;
  struct TNodo *next;
}TNodo;
struct TNodo *q;
int posicion;//Contador pasa saber la posicion en la que quiero insertar
int menu;//Variable que sirve para interactuar con el usuario

//Accion para inicializar la lista
void Inicializar(struct TNodo **m){
  *m = NULL;
  printf("Puntero apuntando a nil.\n");
}


//Accion que carga la lista de a un elemento
void Cargar(struct TNodo **m){
  struct TNodo *aux, *s;
  aux = *m;
  s = *m;
  if(aux == NULL){//Inserto a la cabeza
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->next = NULL;
    *m = aux;
  }else{//Inserto al final
    //Busco el final 
    while(s->next != NULL){
      s = s->next;
    }
    //Inserto
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->next = s->next;
    s->next = aux;
  }
}


//Accion que inserta un elemento en una posicion dada por el usuario
//!Agregar la entrada de pos en el main
//Inserta uno despues de la posicion indicada
void InsertarPos(struct TNodo **m, int pos){
  struct TNodo *aux, *s;
  int i;
  i = 0;
  aux = *m;
  s = *m;
  if(aux != NULL){
    //Busca la posicion
    while(aux->next != NULL && i != pos){
      aux = aux->next;
      i++;
    }
    //Inserto
    if(i == pos){
      s = (TNodo *) malloc(sizeof(struct TNodo *));
      printf("Ingrese un numero: ");
      scanf("%d", &s->info);
      s->next = aux->next;
      aux->next = s;
    }else{
      //No existe la posicion
      printf("LA POSICION NO EXISTE.\n");
    }
  }else{
    //La lista esta vacia
    //Hago insercion a la cabeza
    s = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &s->info);
    s->next = NULL;
    *m = s;
  }
}

//Accion para mostrar la lista completa si no esta vacia
void Mostrar(struct TNodo *m){
  struct TNodo *aux;
  aux = m;
  if(aux == NULL){
    printf("\nNADA QUE MOSTRAR, LA LISTA ESTA VACIA.\n");
  }else{
    printf("\n\tLISTADO: \n");
    while(aux != NULL){//Aca seria aux por que si pongo lo apuntado por aux en el campo next no me imprime el ultimo elemento
      printf(" %d", aux->info);
      aux = aux->next;    
    }
    printf("\n");
  }
}

void main(){
  menu = 0;
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
      Inicializar(&q);
      menu = 0;
    }else if(menu == 2){
      Cargar(&q);
      menu = 0;
    }else if(menu == 3){
      printf("Ingrese la posicion: ");
      //La primera posicion es el cero
      scanf("%d", &posicion);
      InsertarPos(&q, posicion);
      menu = 0;
    }else if(menu == 4){
      Mostrar(q);
    }else if(menu == 5){
      printf("\nCERRANDO PROGRAMA.\n");
    }
  }while(menu != 5);
}