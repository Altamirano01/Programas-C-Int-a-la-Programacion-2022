//Algoritmo problema 3 practico 10
#include<stdio.h>
FILE* f;
FILE* g;
char c;

void main(){
  f = fopen("test.txt", "r");
  g = fopen("gordotravesti.txt", "w");
  while(!feof(f)){
    fgets(c, 1, f);
    fputc(c, g);
  }
  fclose(f);
  fclose(g);
}