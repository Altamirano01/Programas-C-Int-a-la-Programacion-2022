//Algoritmo problema 7 practico 10
#include<stdio.h>
#include<string.h>

typedef char Cadena[80];
char cad;
int cantVocales;
FILE* f;

//Utiliza el archivo de texto creado en el problema 6

void main(){
  cantVocales = 0;
  f = fopen("frases.txt", "r");
  while(!feof(f)){
    cad = fgetc(f);
    if((cad == 'a') || (cad == 'i') || (cad == 'e') || (cad == 'o') || (cad == 'u')){
      cantVocales++;
      printf("\nLa vocal es: %c", cad);
    }
  }
  fclose(f);
}