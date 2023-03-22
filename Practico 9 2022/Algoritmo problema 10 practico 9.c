//Algoritmo problema 10 practico 9
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct TNodo{
  int info;
  struct TNodo *next, *back;
}TNodo;
struct TNodo *q, *p;
int menu;

//Accion para inicializar con elemento ficticio
void InicializarCF(struct TNodo **m, struct TNodo **r){
  *m = (TNodo *) malloc(sizeof(struct TNodo *));
  *r = (TNodo *) malloc(sizeof(struct TNodo *));
  (*m)->next = *r;
  (*m)->back = NULL;
  (*r)->next = NULL;
  (*r)->back = *m;
}

//Acccion para inicializar sin elemento ficticio
void InicializarSF(struct TNodo **m, struct TNodo **r){
  *m = NULL;
  *r = NULL;
}

void Cargar(struct TNodo **m, struct TNodo **r){
  struct TNodo *aux, *aux2;
  int i, cant;
  i = 0;
  cant = 0;
    aux2 = *m;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &cant);
    while(i < cant){
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->back = aux2;
    aux->next = aux2->next;
    aux2->next->back = aux;
    aux2->next = aux;
    i++;
  }
}

void InsertarPos(struct TNodo **m){
  int i;
  int pos;
  struct TNodo *aux, *s;
    printf("Ingrese la posicion: ");
    scanf("%d", &pos);
    i = 0;
    aux = (*m)->next;
    while(aux != NULL && i != pos){
      i++;
      aux = aux->next;
    }
    if(i == pos){
      s = (TNodo *) malloc(sizeof(struct TNodo *));
      printf("Ingrese un numero: ");
      scanf("%d", &aux->info);
      s->back = aux;
      s->next = aux->next;
      s->next->back = s;
      aux->next = s;
    }
}

//Mostrar lista completa
void Mostrar(struct TNodo *m, struct TNodo *r){
  struct TNodo *aux;
    aux = m->next;//Con ficticio
    printf("\n--------------------------------------------------\n");
    printf("\n\tLISTADO\n");
    while(aux != r){
      printf("\n -%d", aux->info);
      printf("\n");
      aux = aux->next;
    }
    printf("\n--------------------------------------------------\n");
}

int main(){
  InicializarCF(&q, &p);
  Cargar(&q, &p);
  Mostrar(q, p);
  return(0);
}