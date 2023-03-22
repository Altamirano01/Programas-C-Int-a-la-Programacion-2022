//Algoritmo problema 2 practica 6
//Facundo Altamirano
#include<stdio.h>
#include<string.h>
float x, y, sup;
char z;
void Cargar(float *a, float *b, char *f){
 printf("Ingrese 't' si es un triangulo o 'r' si es un rectangulo: ");
 scanf("%c", &*f);
  if(*f == 'r'){
   printf("Ingrese el primer lado: ");
   scanf("%f", &*a);
   printf("Ingrese el segundo lado: ");
   scanf("%f", &*b);
  }else{
   printf("Ingrese la base: ");
   scanf("%f", &*a);
   printf("Ingrese la altura: ");
   scanf("%f", &*b);
  }
}

void Calcular(float a, float b, char f, float *area){
 float s;
  if(f == 'r'){
   *area = a * b;
  }else{
   *area = a * b / 2;
  }
}

void Mostrar(float a, float b, char f, float area){
 char mensaje[60];
  if(f == 'r'){
   strcpy(mensaje, "El area del rectangulo dado por los lados ");
  }else{
   strcpy(mensaje, "El area del triangulo dado por la base y la altura ");
  }
  printf("%s %.2f %.2f %.2f\n", mensaje, a, b, area);
}
//Programa principal
void main(){
 Cargar(&x, &y, &z);
 Calcular(x, y, z, &sup);
 Mostrar(x, y, z, sup);

}


