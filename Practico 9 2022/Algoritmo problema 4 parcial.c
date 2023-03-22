//Algoritmo problema 4 parcial
#include<stdio.h>
#include<stdlib.h>
typedef struct TNodo{
  int info;
  struct TNodo *next;
  struct TNodo *back;
}TNodo;
int menu;
struct TNodo *p, *u, *c, *z, *l1, *l2;

void Inicializar(struct TNodo **m, struct TNodo **a, struct TNodo **s, struct TNodo **b, struct TNodo **l1, struct TNodo **l2){
  *m = NULL;
  *a = NULL;
  *s = NULL;
  *b = NULL;
  *l1 = NULL;
  *l2 = NULL;
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

void Unir(struct TNodo **p, struct TNodo **u, struct TNodo **c, struct TNodo **z, struct TNodo **l1, struct TNodo **l2){
  struct TNodo *aux, *aux2, *s, *t;
  //Aux recorre la lista 1
  //T recorre la lista 2
  //aux2 recorre la lista nueva
    t = *c;
    aux = *p;
    *l1 = NULL;
    *l2 = NULL;
    while(aux != NULL){//!Ver si es aux != NULL
      aux2 = *l1;
      if(aux2 == NULL){
        s = (TNodo *) malloc(sizeof(struct TNodo *));
        s->info = aux->info;
        s->back = NULL;
        s->next = NULL;
        *l1 = s;
        *l2 = s;
      }else{
        while(aux2->next != NULL){
          aux2 = aux2->next;
        }
        s = (TNodo *) malloc(sizeof(struct TNodo *));
        s->info = aux->info;
        s->back = aux2;
        s->next = NULL;
        aux2->next = s;
        *l2 = s;
      }
      aux = aux->next;
    }
    if(aux == NULL){
      while(t != NULL){
        aux2 = aux2->next;
        s = (TNodo *) malloc(sizeof(struct TNodo *));
        s->info = t->info;
        s->back = aux2;
        s->next = NULL;
        aux2->next = s;
        *l2 = s;
        t = t->next;
      }
    }
    printf("LISTAS UNIFICADAS\n");
}

void MostrarListasIniciales(struct TNodo *p, struct TNodo *u, struct TNodo *c, struct TNodo *z){
  struct TNodo *aux, *aux2;
  aux = p;
  aux2 = c;
  //!Agregar que pasa cuando la lista esta vacia
  printf("\n\tLISTA 1:\n ");
  while(aux != NULL){
    printf(" %d", aux->info);
    aux = aux->next;
  }
  printf("\n\t LISTA 2:\n ");
  while(aux2 != NULL){
    printf(" %d", aux2->info);
    aux2 = aux2->next;
  }
  printf("\n");
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

int main(){
  menu = 0;
  do{
    printf("\n\tMENU\n");
    printf("1| Inicializar\n");
    printf("2| Cargar primer lista.\n");
    printf("3| Cargar segunda lista.\n");
    printf("4| Unir ambas listas\n");
    printf("5| Mostrar\n");
    printf("6| Salir\n");
    printf("\nINGRESE UN NUMERO SEGUN LA OPERACION QUE DESEE REALIZAR: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case(1):
      Inicializar(&p, &u, &c, &z, &l1, &l2);
      menu = 0;
      break;
    case (2):
      Cargar(&p, &u);
      menu = 0;
      break;
    case(3):
      Cargar(&c, &z);
      menu = 0;
     break;
    case(4):
      Unir(&p, &u, &c, &z, &l1, &l2);
      menu = 0;
     break;
    case(5):
      MostrarListasIniciales(p, u, c, z);
      Mostrar(l1, l2);
      menu = 0;
      break;
    case(6):
      printf("CERRANDO PROGRMA.\n");
     break;
    default:
      printf("\nCerrando programa\n");
      return(0);
      break;
    }
  }while(menu != 6);
}
