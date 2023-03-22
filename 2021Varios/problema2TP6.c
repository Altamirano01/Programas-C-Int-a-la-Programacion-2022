#include<stdio.h>
#include<string.h>
float x;
float y;
float sup;
char z;

void Cargar(float *a, float *b, char *f){ //Carga de datos
 printf("Ingrese una 'r' si es un rectangulo u una 't' si es un triangulo\n");
 scanf("%c", &(*f));
	if((*f) == 'r'){
		printf("Ingrese el primer lado del rectangulo\n");
		scanf("%f", &(*a));
		printf("Ingrese el segundo lado del rectangulo\n");
		scanf("%f", &(*b));	
	}else{
		printf("Ingrese la base del traingulo\n");
		scanf("%f", &(*a));
		printf("Ingrese la altura del triangulo\n");
		scanf("%f", &(*b));}
}
void Calcular(float a, float b, char f, float *area){ //Modifica el valor de las variables
  float s;
	if(f, 'r'){
		*area = a * b;
	}else{
		*area = a * b / 2;}
}		
   
void Mostrar(float *a, float *b, char f, float *area){ //Muestra los resultados de las variables
 char* msge;
	if(f == 'r'){
		msge = "El area del rectangulo dado por los lados ";
	}else{
		msge = "El area del triangulo dado por su base y altura ";}
 printf("%s", msge);
 printf("%f y %f es: %f", *a, *b, *area);
}

void main(){
 Cargar(&x, &y, &z);
 Calcular(x, y, z, &sup);
 Mostrar(&x, &y, z, &sup);
}
 
 
 
 
 
 
