#include<stdio.h>
int num;
int numGanador = 73;
int intentos = 1;
char mensaje;

char Ganador(int n, int nGanador){
 if(n == nGanador){
	return("Ganaste");
 }else {
	return("Perdiste");
 }
}

void main(){

while(intentos < 10){
 printf("Ingrese un numero: \n");
 scanf("%d", &num);
 mensaje = Ganador(num, numGanador);
 if(mensaje = "Ganaste"){
 intentos = 12;
 }else{
  intentos = intentos + 1;
 }
 }
 printf("%s", mensaje);
}


