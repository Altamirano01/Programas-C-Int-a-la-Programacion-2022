//Algoritmo problema 10 practico 10
#include<stdio.h>
FILE* f;


typedef char Cadena[150];

typedef struct TEmpleado{
  Cadena nombre;
  Cadena apellido;
  Cadena dni;
  int cantVentas;
  int edad;
  float sueldo;
}TEmpleado;
TEmpleado reg;
int cant, i;

void main(){
  f = fopen("vendedores.dat", "wb");//En archivos binarios hay que agregar la b para indicarlo
  printf("Ingrese la cantidad de empleados que va a ingresar: ");
  scanf("%d", &cant);
  i = 1;
  while(i <= cant){
    printf("Ingrese el nombre: ");
    scanf("%s", reg.nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", reg.apellido);
    printf("Ingrese el dni: ");
    scanf("%s", reg.dni);
    printf("Ingrese la edad: ");
    scanf("%d", &reg.edad);
    printf("Ingrese la cantidad de ventas realizadas: ");
    scanf("%d", &reg.cantVentas);
    printf("Ingrese el sueldo: ");
    scanf("%f", &reg.sueldo);
    fwrite(&reg, sizeof(reg), 1, f);
    getchar();
    i++;
  }
  fclose(f);
}

