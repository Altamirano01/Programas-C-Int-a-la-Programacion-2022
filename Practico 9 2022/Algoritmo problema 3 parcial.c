//Algoritmo problema parcial 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char Cadena[100];
//Registro para los datos del alumno
typedef struct{
  Cadena nombre;
  int nota1;
  int nota2;
}Testudiante;

typedef struct TNodo{
  Testudiante info;
  struct TNodo *next;
}TNodo;

//Punteros
struct TNodo *p, *q, *r;//3 Listas, la principal, una para aprobados y otra para desaprobados
int menu;

void Inicializar(struct TNodo **p, struct TNodo **q, struct TNodo **r){
  *p = NULL;
  *q = NULL;
  *r = NULL;
}

//Accion que carga la lista general
void Cargar(struct TNodo **m){
  struct TNodo *aux, *s;
  aux = *m;
  s = *m;
  if(aux == NULL){
    //Insercion a la cabeza
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese el nombre: ");
    scanf("%s", aux->info.nombre);
    printf("Ingrese la primer nota: ");
    scanf("%d", &aux->info.nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%d", &aux->info.nota2);
    aux->next = NULL;
    *m = aux;
  }else{
    //Insercion al final
    //Busco el final
    while(s->next != NULL){
      s = s->next;
    }
    //Hago la insercion
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese el nombre: ");
    scanf("%s", aux->info.nombre);
    printf("Ingrese la primer nota: ");
    scanf("%d", &aux->info.nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%d", &aux->info.nota2);
    aux->next = s->next;
    s->next = aux;
  }
}

void Aprobados(struct TNodo *m, struct TNodo **p){//p y q
 struct TNodo *aux, *s, *t;
    aux = m;
    *p = NULL;
    //Aux es el puntero que uso para recorrer la lista principal
    //S es el puntero que uso para crear la lista con los aprobados
    //T es el puntero que uso para recorrer la lista nueva4
    while(aux->next != NULL){
      if(((aux->info.nota1 + aux->info.nota2) / 2) >= 6){
        t = *p;
        if(t == NULL){
          s = (TNodo *) malloc(sizeof(struct TNodo *));
          strcpy(s->info.nombre, aux->info.nombre);
          s->info.nota1 = aux->info.nota1;
          s->info.nota2 = aux->info.nota2;
          s->next = NULL;
          *p = s;
        }else{
          while(t->next != NULL){
            t = t->next;
          }
          s = (TNodo *) malloc(sizeof(struct TNodo *));
          strcpy(s->info.nombre, aux->info.nombre);
          s->info.nota1 = aux->info.nota1;
          s->info.nota2 = aux->info.nota2;
          s->next = NULL;
          t->next = s;
        }
      }
      aux = aux->next;
    }
}

void Desaprobados(struct TNodo *m, struct TNodo **r){//p y q
  struct TNodo *aux, *s, *t;
    aux = m;
    *r = NULL;
    while(aux->next != NULL){
      if((aux->info.nota1 + aux->info.nota2) / 2 < 6){
        t = *r;
        if(t == NULL){
          s = (TNodo *) malloc(sizeof(struct TNodo *));
          strcpy(s->info.nombre, aux->info.nombre);
          s->info.nota1 = aux->info.nota1;
          s->info.nota2 = aux->info.nota2;
          s->next = NULL;
          *r = s;
        }else{
          while(t->next != NULL){
            t = t->next;
          }
          s = (TNodo *) malloc(sizeof(struct TNodo *));
          strcpy(s->info.nombre, aux->info.nombre);
          s->info.nota1 = aux->info.nota1;
          s->info.nota2 = aux->info.nota2;
          s->next = NULL;
          t->next = s;
        }
      }
      aux = aux->next;
    }
}

void Mostrar(struct TNodo *p, struct TNodo *q, struct TNodo *r){
  struct TNodo *aux, *aux2, *aux3;
  aux = p;
  printf("\n\tLISTADO GENERAL:\n");
  while(aux != NULL){
    printf("\nNombre: %s", aux->info.nombre);
    printf("\nPrimer Nota: %d", aux->info.nota1);
    printf("\nSegunda Nota:%d", aux->info.nota2);
    aux = aux->next;
  }
  printf("\n");
  printf("\n\tLISTADO DE APROBADOS:\n");
  aux2 = q;
  while(aux2 != NULL){
    printf("\nNombre: %s", aux2->info.nombre);
    printf("\nPrimer Nota: %d", aux2->info.nota1);
    printf("\nSegunda Nota: %d", aux2->info.nota2);
    aux2 = aux2->next;
  }
  printf("\n");
  printf("\n\tLISTADO DE DESAPROBADOS:\n");
  aux3 = r;
  while(aux3 != NULL){
    printf("\nNombre: %s", aux3->info.nombre);
    printf("\nPrimer Nota: %d", aux3->info.nota1);
    printf("\nSegunda Nota: %d", aux3->info.nota2);
    aux3 = aux3->next;
  }
  printf("\n");
}

int main(){
  menu = 0;
  do{
    printf("\n\tMENU\n");
    printf("1| Cargar.\n");
    printf("2| Aprobados.\n");
    printf("3| Desaprobados.\n");
    printf("4| Mostrar listas completas.\n");
    printf("5| Inicializar.\n");
    printf("6| Salir.\n");
    printf("\nINGRESE EL NUMERO DE OPERACON QUE DESEE REALIZAR: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case (1):
      Cargar(&p);
      menu = 0;
      break;
    case(2):
      Aprobados(p, &q);
      menu = 0;
     break;
    case(3):
      Desaprobados(p, &r);
      menu = 0;
     break;
    case(4):
      Mostrar(p, q, r);
      menu = 0;
      break;
    case(5):
      Inicializar(&p, &q, &r);
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
