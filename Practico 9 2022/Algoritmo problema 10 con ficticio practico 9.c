//Algoritmo problema 10 con fictico practico 9
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
  *m = (TNodo *) malloc(sizeof(struct TNodo *));
  *a = (TNodo *) malloc(sizeof(struct TNodo *));
  (*m)->next = *a;
  (*m)->back = NULL;
  (*a)->back = *m;
  (*a)->next = NULL;
}

void Cargar(struct TNodo **m, struct TNodo **a){
  struct TNodo *aux, *s;
    aux = *m;//* Si pongo a m->next me apuntaria al puntero a y se me romperia el ficticio
    s = *a;//Inserto del final
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->back = s->back;//Tengo que usar si o si un auxiliar por que si uso los principales solo me funcionaria para cuando hago una unica insercion
    aux->next = s;
    s->back->next = aux;
    s->back = aux;
}

void InsertarPos(struct TNodo **m, struct TNodo **a, int pos){
  struct TNodo *aux, *s;
  int i;
  //!Hay que agregar mas casos de pos ya que hay que tener en cuenta los elementos ficticios
  //! y que no deje ingresar en la posicion 0
    aux = *m;
    s = *m;
    i = 0;
    //Busco la posicion
    while(s->next != a && i != pos){ //Ojo con la comparacion entre punteros porque son distintos capaz el programa no lo tome, si no lo toma tengo que poner que s->next != NULL
      s = s->next;
    }
    if(i == pos){
    //Agrego el nuevo elemento
    aux = (TNodo *) malloc(sizeof(struct TNodo *));
    printf("Ingrese un numero: ");
    scanf("%d", &aux->info);
    aux->back =  s;
    aux->next = s->next;
    s->next->back = aux;
    s->next = aux;
    }else{
      printf("POSICION INVALIDA.\n");
    }
}

void Mostrar(struct TNodo *m, struct TNodo *a){
  struct TNodo *aux;
    aux = m->next;
    printf("\n\tLISTADO: \n");
    while(aux != a){
      printf("%d", aux->info);
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