#include<stdio.h>
#include<string.h>
float ax;
float bx;
float c;
float d;
char raices;
 
 
 //Agregar a cada raiz un strcpy(raices, "Mensaje") y al final un printf de raices
 
 
void main(){
 printf("Ingrese el coeficiente de ax \n");
 scanf("%f", &ax); 
 printf("Ingrese el coeficiente de bx \n");
 scanf("%f", &bc); 
 printf("Ingrese el coeficiente de c \n");
 scanf("%f", &c); 

	if((ax == 0) & (bx == 0)){
		raices = "La ecuacion es degenerada";
		strcpy("%s \n", raices);
	}else if((ax == 0) & (bx != 0)){
	    raices = "Existe una unica raiz";
		strcpy("%s \n", raices);
	}else if((ax !=0) & (bx !=0)){
		d = bx * bx - 4 * ax * c;
		  if(d > 0){
			raices = "Existen dos raices reales";
			strcpy("%s \n", raices);
		  }else if(d < 0){
				raices = "Existe una sola raiz";
				strcpy("%s \n", raices);
		  }else if(d == 0){
				raices = "Existen dos raices complejas";
				strcpy("%s \n", raices);
		  }
	}
}