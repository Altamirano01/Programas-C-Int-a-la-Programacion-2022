//Algoritmo problema 11 practico 10
#include<stdio.h>
#include<string.h>
#define M 200
//Tipo cadena
typedef char Cadena[200];

Cadena nombExt;
//Registro de una persona
typedef struct TPersona{
  Cadena nombre;
  int edad;
}TPersona;

TPersona reg, aux;

//TData
typedef struct TData{
  TPersona a[M];
  int cant;
}TData;

TData arreglo;

FILE* f;
int i;

//Accion para cargar arreglo
void CargarArreglo(TData *q){
  int i;
    printf("Ingrese la cantidad de personas a cargar: ");
    scanf("%d", &q->cant);
    for(i = 0; i < q->cant; i++){
      printf("Ingrese el nombre: ");
      scanf("%s", q->a[i].nombre);
      printf("Ingrese la edad: ");
      scanf("%d", &q->a[i].edad);
    }
}

void main(){
  CargarArreglo(&arreglo);
  printf("Ingrese el nombre externo del archivo con formato: ");
  scanf("%s", &nombExt);
  f = fopen(nombExt, "wb");
  //Llenar el archivo con los datos del arreglo
  i = 0;
  while(i < arreglo.cant){
    strcpy(reg.nombre, arreglo.a[i].nombre);
    reg.edad = arreglo.a[i].edad;
    fwrite(&reg, sizeof(reg), 1, f);
    i++;
  }
  fclose(f);
  //Abrir el archivo modo lectura
  f = fopen(nombExt, "rb");
  //Leer los datos almacenados en el archivo
  printf("\n\tDATOS ALMACENADOS: \n");
  //!No me lee los nombres nomas
  while(fread(&aux, sizeof(TPersona), 1, f) != 0 ){//!Ver lo de la diapositiva 13 del pdf
    printf("Nombre: %s\n", aux.nombre);
    printf("Edad: %d\n", aux.edad);
    printf("\n");
  }
  fclose(f);

}