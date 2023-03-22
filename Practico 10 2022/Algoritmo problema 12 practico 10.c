//Algoritmo problema 12 practico 10
#include<stdio.h>
#include<string.h>
FILE* f;
FILE* g;
#define M 200
typedef char Cadena[150];
typedef struct TPersona{
  Cadena nombre;
  int edad;
}TPersona;

typedef struct TData{
  TPersona a[M];
  int cant;
}TData;
TData arreglo;
TData a2;

TPersona reg, aux;
int i, j;

void main(){
  f = fopen("altamirano.dat", "rb");
  j = 0;
  a2.cant = 0;
  //Guardo los mayores de edad en el arreglo
  while(!feof(f)){
    fread(&reg, sizeof(reg), 1, f);
    a2.a[j] = reg;
    a2.cant++;
    j++;
  }


  //!El problema esta en que no llena bien el arreglo



  printf("DATOS LEIDOS.\n");
  fclose(f);
  // Codigo para ver los datos cargados en el archivo
  // Es auxiliar
  printf("Arreglo.\n");
  for(j = 0; j < a2.cant; j++){
    printf("Name %s\n", a2.a[j].nombre);
    printf("Age %d\n", a2.a[j].edad);
  }

  //Escribo los datos del arreglo en otro archivo nuevo
  g = fopen("mayores.dat", "wb");
  i = 0;
  printf("Escribiendo datos...\n");
  while(i < a2.cant){
    strcpy(reg.nombre, a2.a[i].nombre);
    reg.edad = a2.a[i].edad;
    fwrite(&reg, sizeof(reg), 1, g);
    i++;
  }
  printf("DATOS ESCRITOS.\n");
  fclose(g);
  //Voy a mostrar lo que esta guardado en mayores.dat
  g = fopen("mayores.dat", "rb");
  printf("\n\tDatos de mayores.dat: \n");
  while(fread(&aux, sizeof(TPersona), 1, g) != 0 ){
    printf("Nombre: %s\n", aux.nombre);
    printf("Edad: %d\n", aux.edad);
    printf("\n");
  }
  fclose(g);
}