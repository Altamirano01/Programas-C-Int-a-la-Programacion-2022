//Algoritmo problema 3 practico 9
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//Lexico
typedef struct Telemcar{
    char info;
    struct Telemcar *next;
}Telemcar;
struct Telemcar *sec, *aux;
int contador;
int menu;

//Perfiles 
void InsertarPrimero(struct Telemcar **m);
void Cargar(struct Telemcar **m);
void CantVocales(struct Telemcar *r, int *cant);
void Mostrar(struct Telemcar *q);
int Vacia(struct Telemcar *m);

//Inicio
int main(){//PONGO INT MAIN PARA CORTAR EL SWITCH EN UN CASO ESPECIFICO
  sec = NULL;//Inicializo
  aux = NULL;
  contador = 0;
   do{
    printf("\n\tMENU\n");
    printf("1| Insertar el primero\n");
    printf("2| Ingresar otro elemento\n");
    printf("3| Contar las vocales\n");
    printf("4| Mostrar la palabra\n");
    printf("5| Salir\n");
    printf("\nINGRESE UN NUMERO SEGUN LA OPERACION QUE DESEE REALIZAR: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case (1):
      InsertarPrimero(&sec);
      menu = 0;
      break;
    case(2):
      Cargar(&sec);
      menu = 0;
     break;
    case(3):
      CantVocales(sec, &contador);
      menu = 0;
     break;
    case(4):
      Mostrar(sec);
      menu = 0;
      break;
    case(5):
      printf("\nCerrando...\n");
     break;
    default:
      printf("\nCerrando programa\n");
      return(0);
      break;
    }
  }while(menu != 5);
}

int Vacia(struct Telemcar *m){
  if(m == NULL){
    return(0);//Esta vacia
  }else{
    return(1);//Tiene un elemento por lo menos
  }
}

void InsertarPrimero(struct Telemcar **m){
  struct Telemcar *aux;
  *m = (Telemcar *) malloc(sizeof(struct Telemcar *));
  printf("Ingrese un caracter: ");
  while(getchar() != '\n');
  (*m)->info = getchar();
  (*m)->next = NULL;
}

void Cargar(struct Telemcar **m){
  struct Telemcar *aux, *s;
    aux = *m;
    s = *m;
    //Insertar al final
    //Busco la posicion final
    while(s->next != NULL){
      s = s->next;
    }
    //Inserto el doblete
    aux = (Telemcar *) malloc(sizeof(struct Telemcar *));
    printf("Ingrese un caracter: ");
    while(getchar() != '\n');
    aux->info = getchar();
    aux->next = s->next;
    s->next = aux;    
}



void CantVocales(struct Telemcar *m, int *cant){
  //Lexico local
  struct Telemcar *aux;
  //!Ver porque no cuenta las vocales xd
  //Inicio
    aux = m;
    while(aux != NULL){//Si pongo aux->next se me corta antes de llegar al final, es decir, no mira el ultimo
      if((aux->info == 'a') || (aux->info == 'e') || (aux->info == 'i') || (aux->info == 'o') || (aux->info == 'u')){
        cant++;
      }
       aux = aux->next;
    }
    printf("\nSE CONTARON LAS VOCALES DE LA PALABRA.\n");
    printf("\nLA CANTIDAD DE VOCALES ES: %d\n", *cant);
}

void Mostrar(struct Telemcar *q){
  struct Telemcar *aux2;
  aux2 = q;
  if(Vacia(aux2) != 0){
    printf("\nLA PALABRA INGRESADA ES: \n");
    while(aux2 != NULL){
      printf("%c", aux2->info);
      aux2 = aux2->next;
   }
   printf("\n");
  }else{
    printf("\nERROR! LA LISTA ESTA VACIA.");
  } 
}
