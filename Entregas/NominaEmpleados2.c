//Algoritmo trabajo practico integrador
//Altamirano Facundo, Romero Martin, Urruchua Iker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 1000

typedef char Cadena[40];
typedef struct{
    Cadena a[N];
    int cant;
}TData;
TData lista;
Cadena nuevoApellido, apellido, apellidoDos;
char mensaje[200];

int posicion, menu;
//Recibe el registro e informa si esta vacio o no
bool Vacia(TData q);
//Recibe el registro e informa si esta lleno o no
bool Llena(TData q);
//Recibe el registro y un nuevo apellido, lo inserta en el arreglo e incrementa
//la cantidad de elementos en uno
void InsertarApellido(TData *q, Cadena nuevApe);
//Recibe el registro y un nueveo apellido, lo busca en el arreglo, lo borra y decrementa
//la cantidad de elementos en uno
void SuprimirUno(TData *q, Cadena nuevApe, int pos);
//Muestra en pantalla los apellidos cargados del arreglo
void MostrarLista(TData q);
//Recibe el registro y un apellido a encontrar, recorre el arreglo y si esta, devuelve la posicion
void EncontrarUno(TData q, int *pos, Cadena ap);
//Recibe el registro y un apellido, devuelve V o F si esta repetido o no
bool HayRepetidos(TData q, Cadena ap);
//Recibe el registro, un apellido y la posicion, devuelve el arreglo con el apellido modificado
void ModificarApellido(TData *q, Cadena a, int pos);

int main(){
    lista.cant = 0;
    do
  {
    strcpy(mensaje, "\n \tMENU\n");
    printf("%s", mensaje);
    strcpy(mensaje,"1| Alta de empleado.\n"
                   "2| Baja de empleado.\n"
                   "3| Modificar datos de empleado.\n"
                   "4| Listar.\n"
                   "5| Buscar a un empleado.\n"
                   "6| Salir.\n");
    printf("%s", mensaje);
		strcpy(mensaje, "SELECCIONE UN NUMERO QUE CORRESPONDA A LA OPERACION QUE DESEE REALIZAR.\n");
		printf("%s", mensaje);
        scanf(" %d", &menu);
    switch  (menu)
    {
      case (1):
        printf("Alta de empleado.\n");
        if (Llena(lista)) {
          printf("ERROR LA LISTA ESTA LLENA\n");
        }else{
          printf("Ingrese el apellido que desea dar de alta (sin espacios): ");
          scanf(" %s", nuevoApellido);
          if(HayRepetidos(lista, nuevoApellido) != true){
          InsertarApellido(&lista,nuevoApellido);
          }else{
            printf("ERROR EL APELLIDO YA ESTA EN LA LISTA. \n");
          }
        }
        menu = 0;
      break;
      case (2):
        printf("Baja de empleado\n");
        if (Vacia(lista)) {
          printf("ERROR LA LISTA ESTA VACIA.\n");
        }else{
          printf("Ingrese el apellido que desea borrar: ");
          scanf(" %s", apellido);
          EncontrarUno(lista, &posicion, apellido);
          SuprimirUno(&lista, apellido, posicion);
        }
        menu = 0;
      break;
      case (3):
        printf("Modificar datos de empleado \n");
        if (Vacia(lista)) {
          printf("ERROR LA LISTA ESTA VACIA.\n");
        }else{
          printf("Ingrese el apellido que desea modificar: ");
          scanf(" %s", apellido);
          EncontrarUno(lista, &posicion, apellido);
          if(posicion != -1){
            printf("Ingrese el apellido modificado: ");
            scanf(" %s", apellidoDos);
            ModificarApellido(&lista, apellidoDos, posicion);
          }
        }
        menu = 0;
      break;
      case (4):
        printf("Listar.\n");
        if(Vacia(lista)){
            printf("LA LISTA ESTA VACIA, NADA QUE MOSTRAR.\n");
        }else{
            MostrarLista(lista);
        }
        menu = 0;
      break;
      case (5):
        printf("Buscar a un empleado.\n");
        if(Vacia(lista)){
          printf("ERROR LA LISTA ESTA VACIA\n");
        }else{
          printf("Ingrese el apellido que desea buscar (sin espacios): ");
          scanf(" %s", apellido);
          EncontrarUno(lista, &posicion, apellido);
        }
        menu = 0;
      break;
      case (6):
        printf("Adios.\n");
      break;
      default:
        printf ("Cerrando el programa.\n");
        return 0;
      break;
    }
  }while(menu != 6);
}


//a
bool Vacia(TData q){
    if(q.cant == 0){
        return true;
    }else{
        return false;
    }
}
//b
bool Llena(TData q){
    if(q.cant >= 1000){
        return true;
    }else{
        return false;
    }
}
//c
void InsertarApellido(TData *q, Cadena nuevApe){
        strcpy(q->a[q->cant], nuevApe);
        q->cant++;
        printf("APELLIDO CARGADO.\n");
}
//d
void SuprimirUno(TData *q, Cadena nuevApe, int pos){
  if (pos != -1){
    while(pos < q->cant){
          strcpy(q->a[pos], q->a[pos + 1]);
          pos++;
    }
    q->cant = q->cant - 1;
    printf("\nAPELLIDO BORRADO.");
  }
}
//e
void MostrarLista(TData q){
    int i;
     printf("LISTADO:\n");
     for(i = 0; i < q.cant; i++){
        printf("%s, ", q.a[i]);
     }
}
//f
void EncontrarUno(TData q, int *pos, Cadena ap){
    int i;
     *pos = -1;
     for(i = 0; i < q.cant; i++){
        if(strcmp(q.a[i], ap) == 0){
            *pos = i;
            printf("SE HA ENCONTRADO EL APELLIDO, ESTA EN LA POSICION: %d\n", *pos);
            break;
        }
     }
     if(*pos == -1){
        printf("EL APELLIDO NO FUE ENCONTRADO.\n");
     }
}

//g
bool HayRepetidos(TData q, Cadena ap){
    int i;
     for(i = 0; i < q.cant; i++){
        if(strcmp(q.a[i], ap) == 0){
            return true;
        }else{
            return false;
        }
     }
}
//Accion auxiliar
void ModificarApellido(TData *q, Cadena a, int pos){
    strcpy(q->a[pos], a);
    printf("APELLIDO MODIFICADO.\n");
}