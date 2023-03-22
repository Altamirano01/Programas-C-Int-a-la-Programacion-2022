#include<stdio.h>
int a;
float potencia = 1;
int y;
int i;

void main(){
	printf("Ingrese la base: \n");
	scanf("%d", &a);
	printf("Ingrese el exponente: \n");
	scanf("%d", &y);
		for(i = 1; i <= y; i++){
			potencia = potencia * i;
		}
	printf("El resultado de la potencia es: \n %f", potencia);
}