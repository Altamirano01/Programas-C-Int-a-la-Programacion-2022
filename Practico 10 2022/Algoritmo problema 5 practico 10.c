//Algoritmo problema 5 practico 10
#include<stdio.h>
#include<string.h>
char frase[80];
FILE* f;


void main(){
  f = fopen("prob4.txt", "a");
  while(strcmp(frase, "fin") == 1){
    printf("Ingrese la frase: ");
    scanf("%s", &frase);
    fputs(frase, f);//ingresa una cadena al archivo, primero va la cadena y luego el nombre interno
  }
  fclose(f);
}