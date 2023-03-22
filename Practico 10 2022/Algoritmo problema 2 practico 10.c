//Algoritmo problema 2 practico 10
#include<stdio.h>
char c;
FILE* f;
int i;

void main(){
  f = fopen("test.txt", "a");
  i = 1;
  while(!feof(f) && i <= 20){
    printf("Ingrese un caracter: ");
    scanf("%c", &c);
    fputc(c, f);
    getchar();
    i++;
  }
  fclose(f);
}