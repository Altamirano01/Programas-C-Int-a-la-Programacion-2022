//Algoritmo problema 4 practico 9
#include<stdio.h>
#include<stdlib.h>
//!Ver si anda bien el insertar y eliminar en una posicion dada, con las pruebas creo que anda
//Lexico
typedef struct TNodo{
  int info;
  struct TNodo *next;
}TNodo;
struct TNodo *sec;//Puntero
int posicion;
int menu;//Sirve para interactuar con el programa

//Perfiles
void InsertarC(struct TNodo **m);
void InsertarF(struct TNodo **m);
void Inicializar(struct TNodo **m);
void VaciarLista(struct TNodo **m);
void InsertarPos(struct TNodo **m, int pos);
void EliminarC(struct TNodo **m);
void EliminarPos(struct TNodo **m, int pos);
void Mostrar(struct TNodo *m);


//Inicio
int main(){
  sec = NULL;
  menu = 0;
  posicion = 0;
  do{
    printf("\n\tMENU\n");
    printf("1| Insertar a la cabeza\n");
    printf("2| Insertar al final\n");
    printf("3| Inicializar.\n");
    printf("4| Vaciar lista.\n");
    printf("5| Insertar en una posicion\n");
    printf("6| Eliminar a la cabeza\n");
    printf("7| Eliminar en una posicion\n");
    printf("8| Mostrar lista.\n");
    printf("9| Salir\n");
    printf("\nINGRESE UN NUMERO SEGUN LA OPERACION QUE DESEE REALIZAR: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case (1):
      InsertarC(&sec);
      menu = 0;
      break;
    case(2):
      InsertarF(&sec);
      menu = 0;
     break;
    case(3):
      Inicializar(&sec);
      menu = 0;
     break;
    case(4):
      VaciarLista(&sec);
      menu = 0;
      break;
    case(5):
      printf("Ingrese la posicion: ");
      scanf("%d", &posicion);
      InsertarPos(&sec, posicion);
      menu = 0;
     break;
    case(6):
      EliminarC(&sec);
      menu = 0;
     break;
    case(7):
      printf("Ingrese la posicion: ");
      scanf("%d", &posicion);
      EliminarPos(&sec, posicion);
      menu = 0;
     break;
    case(8):
      Mostrar(sec);
      menu = 0;
     break;
    case(9):
      printf("CERRANDO PROGRMA.\n");
     break;
    default:
      printf("\nCerrando programa\n");
      return(0);
      break;
    }
  }while(menu != 9);

}

//Acciones y funciones

void InsertarC(struct TNodo **m){
  struct TNodo *aux;
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->next = *m;
    *m = aux;
}
void InsertarF(struct TNodo **m){
  struct TNodo *aux, *s;
    s = *m;
    while(s->next != NULL){
      s = s->next;
    }
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->next = s->next;
    s->next = aux;
}

void Inicializar(struct TNodo **m){
  *m = NULL;
}

void VaciarLista(struct TNodo **m){
  struct TNodo *aux;
  if(m != NULL){
    while (m != NULL){
      aux = *m;
      *m = (*m)->next;
      free(aux);
      printf("SE VACIO LA LISTA.\n");
    }
  }else{
    printf("LISTA VACIA.\n");
  }
}//Para que funcione debe haber inicializado la lista primero si no se corta

void InsertarPos(struct TNodo **m, int pos){
  struct TNodo *aux, *s;
  int i;
    i = 0;
    aux = *m;
    if(aux == NULL || pos == 0){
      aux = (TNodo *) malloc(sizeof(struct TNodo *));
      printf("Ingrese un numero: ");
      scanf("%d", &aux->info);
      aux->next = *m;
      *m = aux;
    }
    while(aux->next != NULL && i != pos){
      aux = aux->next;
      i++;
    }
    if(i == pos && pos > 0){
      s = (TNodo *) malloc(sizeof(struct TNodo *));
      printf("Ingrese un numero: ");
      scanf("%d", &s->info);
      s->next = aux->next;
      aux->next = s;
    }
    else{
      printf("POSICION NO ENCONTRADA.\n");
    }
}


void EliminarC(struct TNodo **m){
  struct TNodo *aux;
    aux = *m;
    *m = (*m)->next;
    free(aux);
}

void EliminarPos(struct TNodo **m, int pos){
  struct TNodo *aux, *s;
  int i;
    i = 0;
    aux = *m;
    while(aux->next != NULL && i != pos - 1){
      aux = aux->next;
      i++;
    }
    if(i == pos - 1 ){
      s = aux->next;
      aux->next = s->next;
      free(s);
    }else{
      printf("POSICION NO ENCONTRADA. \n");
    }
}
void Mostrar(struct TNodo *m){
  struct TNodo *aux;
  aux = m;
  printf("LISTADO: \n");
    while(aux != NULL){
      printf("%d ", aux->info);
      aux = aux->next;
    }
  printf("\n");
}



