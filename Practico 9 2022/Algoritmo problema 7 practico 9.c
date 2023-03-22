//Algoritmo problema 7 practico 9
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct{
  char nombre[100];
  char apellido[100];
  char telefono[100];
  char direccion[100];
  int edad;
}Templeado;

typedef struct TNodo{
  Templeado info;
  struct TNodo *next;
}TNodo;
struct TNodo *q, *r, *s;
char nombre[100];
int menu;
int posicion;

//Perfiles de las acciones y funciones
void InsertarC(struct TNodo **m);
void InsertarF(struct TNodo **m);
void Inicializar(struct TNodo **m);
void VaciarLista(struct TNodo **m);
bool Vacia(struct TNodo *m);
void Buscar(struct TNodo *m, char nom[100], int *pos);
void MuestraReg(struct TNodo *m, int pos);
void Mostrar(struct TNodo *m);
void EliminarPos(struct TNodo **m, int pos);
void InsertarPos(struct TNodo **m);



//Inicio
int main(){
  posicion = 0;
  q = NULL;
  r = NULL;
  s = NULL;
  menu = 0;
  do{
    printf("\n\tMENU\n");
    printf("1| Insertar a la cabeza\n");
    printf("2| Insertar al final\n");
    printf("3| Inicializar.\n");
    printf("4| Vaciar lista.\n");
    printf("5| Buscar un nombre en la lista y determinar su posicion en ella.\n");
    printf("6| Mostrar un nombre solicitado de la lista.\n");
    printf("7| Mostrar lista completa.\n");
    printf("8| Eliminar en una posicion.\n");
    printf("9| Insertar en una posicion.\n");
    printf("10| Salir\n");
    printf("\nINGRESE UN NUMERO SEGUN LA OPERACION QUE DESEE REALIZAR: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case (1):
      InsertarC(&q);
      menu = 0;
     break;
    case (2):
      InsertarF(&q);
      menu = 0;
     break;
    case (3):
      Inicializar(&q);
      menu = 0;
     break;
    case (4):
      VaciarLista(&q);
      menu = 0;
     break;
    case (5):
      printf("Ingrese el nombre a buscar: ");
      scanf("%s", nombre);
      Buscar(q, nombre, &posicion);
      menu = 0;
     break;
    case (6):
      printf("Ingrese el nombre a buscar: ");
      scanf("%s", nombre);
      Buscar(q, nombre, &posicion);
      MuestraReg(q, posicion);
      menu = 0;
     break;
    case (7):
      Mostrar(q);
      menu = 0;
     break;
    case (8):
      printf("Ingrese el nombre a buscar: ");
      scanf("%s", nombre);
      Buscar(q, nombre, &posicion);
      EliminarPos(&q, posicion);
      menu = 0;
     break;
    case(9):
      InsertarPos(&q);
      menu = 0;
     break;
    case(10):
      printf("\nCerrando...\n");
     break;
    default:
      printf("\nOPCION INVALIDA.\n");
      printf("\nCERRANDO PROGRAMA.\n");
      return(0);
     break;
    }
  }while(menu != 10);
}

//Acciones y funciones

//Insertar al comienzo de la lista
void InsertarC(struct TNodo **m){
  struct TNodo *aux;
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese el nombre: ");
    scanf("%s", aux->info.nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", aux->info.apellido);
    printf("Ingrese el telefono: ");
    scanf("%s", aux->info.telefono);
    printf("Ingrese la direccion: ");
    scanf("%s", aux->info.direccion);
    printf("Ingrese la edad: ");
    scanf("%d", &aux->info.edad);
    aux->next = (*m)->next;
    (*m)->next = aux;

}

//Insertar al final de la lista
void InsertarF(struct TNodo **m){
  struct TNodo *aux, *s;
    s = *m;
    while(s->next != NULL){
      s = s->next;
    }
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese el nombre: ");
    scanf("%s", aux->info.nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", aux->info.apellido);
    printf("Ingrese el telefono: ");
    scanf("%s", aux->info.telefono);
    printf("Ingrese la direccion: ");
    scanf("%s", aux->info.direccion);//Ver porque aca no se pone el &, al igual que en todas las otras entradas de datos
    printf("Ingrese la edad: ");
    scanf("%d", &aux->info.edad);//Aca si tiene que ir el aspersen&
    aux->next = NULL;
    s->next = aux;
}

//Inicializar la lista con el elemento fictico
void Inicializar(struct TNodo **m){
  *m = (TNodo *) malloc(sizeof(struct TNodo *));
  (*m)->next = NULL;
}

//Vaciar lista completa
void VaciarLista(struct TNodo **m){
  struct TNodo *aux;
  if(m != NULL){
    while (m != NULL){
      aux = *m;
      *m = (*m)->next;
      free(aux);
    }
  printf("SE VACIO LA LISTA.\n");
  }else{
    printf("LISTA VACIA.\n");
  }
}

//Ver si esta vacia
bool Vacia(struct TNodo *m){
  if(m == NULL){
    return(true);
  }else{
    return(false);
  }
}

//Buscar un nombre e informar su posicion en la lista
void Buscar(struct TNodo *m, char nom[100], int *pos){
  struct TNodo *aux;
  int i;
    i = 0;
    aux = m->next;
    while((aux != NULL) && (strcpy(aux->info.nombre, nom) == 1)){
      i++;
      aux = aux->next;
    }
    if(aux == NULL){
      *pos = -1;
      printf("%d", *pos);
    }else{
      *pos = i;
      printf("%d", *pos);
    }
}    //*No informa la posicion si esta o no

//Mostrar datos de una persona de acuerdo a su posicion en la lista
void MuestraReg(struct TNodo *m, int pos){//! NO ANDA
  struct TNodo *aux;
  int i;
    aux = m;
    while((aux != NULL) && (i != pos)){
      aux = aux->next;
      i++;
    }
    if(i == pos){
      printf("\n Nombre: %s", aux->info.nombre);
      printf("\n Apellido: %s", aux->info.apellido);
      printf("\n Telefono: %s", aux->info.telefono);
      printf("\n Direccion: %s", aux->info.direccion);
      printf("\n Edad: %d", aux->info.edad);
    }
}
//Mostrar lista completa
void Mostrar(struct TNodo *m){
  struct TNodo *aux;
    aux = m->next;
    printf("\n--------------------------------------------------\n");
    printf("\n\tLISTADO\n");
    while(aux != NULL){
      printf("\n Nombre: %s", aux->info.nombre);
      printf("\n Apellido: %s", aux->info.apellido);
      printf("\n Telefono: %s", aux->info.telefono);
      printf("\n Direccion: %s", aux->info.direccion);
      printf("\n Edad: %d", aux->info.edad);
      printf("\n");
      aux = aux->next;
    }
    printf("\n--------------------------------------------------\n");
}

//Eliminar datos de una persona de acuerdo a su poscion en la lista
void EliminarPos(struct TNodo **m, int pos){
  int i;
  struct TNodo *aux, *aux2;
    aux = *m;
    aux2 = *m;
    //Busco la posicion que quiero borrar
    while(i != pos){
      aux = aux->next;
      i++;
    }
    //Hago apuntar un puntero al anterio a la posicion que quiero borrar
    while(i != pos - 1){
      aux2 = aux->next;
      i++;
    }
    //Borro la posicion
    aux2->next = aux->next;
    free(aux);
    printf("DATOS BORRADOS.\n");
}

//Insertar un elemento nuevo en una posicion dada
void InsertarPos(struct TNodo **m){
  struct TNodo *aux, *s;
  int i, p;
    i = 0;
    aux = (*m)->next;
    printf("INGRESE LA POSICION: ");
    scanf("%d", &p);
    while(aux->next != NULL && i != p){
      i++;
      aux = aux->next;
    }
    if(i == p){
      s = (TNodo *) malloc(sizeof(struct TNodo *));
      printf("Ingrese el nombre: ");
      scanf("%s", aux->info.nombre);
      printf("Ingrese el apellido: ");
      scanf("%s", aux->info.apellido);
      printf("Ingrese el telefono: ");
      scanf("%s", aux->info.telefono);
      printf("Ingrese la direccion: ");
      scanf("%s", aux->info.direccion);//Ver porque aca no se pone el &, al igual que en todas las otras entradas de datos
      printf("Ingrese la edad: ");
      scanf("%d", &aux->info.edad);
      s->next = aux->next;
      aux->next = s;
    }else{
      printf("POSICION NO ENCONTRADA.\n");
    }
}
