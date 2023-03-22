//Algoritmo problema 13 practico 10
#include<stdio.h>
#include<string.h>
typedef char Cadena[200];
Cadena nom;
long int posicion;
int cant, i;
typedef struct TEstudiante{
  Cadena nombre;
  Cadena apellido;
  int edad;
}TEstudiante;

TEstudiante reg;
FILE* f;

void Buscar(FILE* g, Cadena n, long int *pos){
  TEstudiante aux;
    while(fread(&aux, sizeof(aux), 1, g) != 0){
      if(strcmp(aux.nombre, n) == 0){
        *pos = ftell(g);
      }else{
        //*pos = -1;//Ver por que si agrego que retorne -1 si no esta me retorna siempre esto y no 
      }
    }
    printf("La posicion en el archivo es: %ld", *pos);
}

void main(){
  //Llenar el archivo con los datos
  f = fopen("estudiantes.dat", "wb");
  printf("Ingrese la cantidad de estudiantes que va a ingresar: ");
  scanf("%d", &cant);
  i = 0;
  while(i < cant){
    printf("Ingrese el nombre: ");
    scanf("%s", &reg.nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", &reg.apellido);
    printf("Ingrese la edad: ");
    scanf("%d", &reg.edad);
    fwrite(&reg, sizeof(reg), 1, f);
    i++;
  }
  printf("DATOS CARGADOS.\n");
  fclose(f);
  //Ahora voy a buscar un estudiante por nombre
  f = fopen("estudiantes.dat", "rb");
  printf("Ingrese el nombre a buscar: ");
  scanf("%s", nom);
  Buscar(f, nom, &posicion);
  fclose(f);
}