 //Algoritmo problema 3 practico 8
//all Preguntas: 
//I) PREGUNTA: ¿Qué sucede si cargo un arreglo de registros hasta la mitad? ¿La otra mitad ocupa espacio?
//Si, ocupa espacio por mas que no se use, por eso es una desventaja
//II) PREGUNTA:¿Qué sucede si tengo un registro de 5 campos y cargo 2? ¿Los otros 3 campos ocupan espacio?
//Si, ocupa espacio porque es como un bloque
//!ver como hacer la entrada porque si pongo el espacio me lo toma como otra cosa
#include<stdio.h>
//Lexico
#define M 250
typedef struct TPersona{
  char nombre [50];
  char apellido [50];
  int edad;//De 1 a 120
}TPersona;//Registro
typedef struct TData{
  struct TPersona a[M];
  int cant;//De 1 a 250
}TData;//Arreglo de registro
struct TData persona;
int contador;

//Accion de carga
void Cargar(struct TData *q){
 int i;
  printf("\nINGRESE LA CANTIDAD DE PERSONAS A CARGAR, entre 1 y 250: ");
  scanf("%d", &q->cant);
  if((q->cant < 1) || (q->cant > 250)){
    printf("\nERROR!, NUMERO INVALIDO.\n");
    q->cant = 0;
  }
  for(i = 0; i < q->cant;i++){
    printf("Ingrese un apellido: ");
    scanf("%s", &q->a[i].apellido);
    printf("Ingrese el nombre: ");
    scanf("%s", &q->a[i].nombre);
    printf("Ingrese la edad: ");
    scanf("%d", &q->a[i].edad);
  }
}
//Accion para saber cuantas personas son menores a 18
void Menores(struct TData q){
 int i;
 printf("\nA CONTINUACION SE LISTARAN LAS PERSONAS MENORES DE EDAD: \n");
 for(i = 0; i < q.cant; i++){
    if(q.a[i].edad < 18){
      printf("\n%s  %s", q.a[i].apellido, q.a[i].nombre);
    }else{
      printf("NOTHING");
    }
 }
}
//Accion para mostrar la lista de personas
void Mostrar(struct TData q){
 int i;
 printf("\n\n\tLISTADO\n");
 printf("\n");
  for(i = 0; i < q.cant; i++){
    printf("Nombre: %s Apellido: %s Edad: %d\n", q.a[i].nombre, q.a[i].apellido, q.a[i].edad);
  }}
void main(){
  Cargar(&persona);
  Menores(persona);
  Mostrar(persona);
}