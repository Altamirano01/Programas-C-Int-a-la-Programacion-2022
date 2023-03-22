//Algoritmo problema 1 practico 10
#include<stdio.h>
FILE* f;
char cad[128];
void main(){
  f = fopen("test.txt", "r");
  if(f != NULL){
  while(!feof(f)){
    fread(cad, 128, f);
    printf("%s", cad);
  }
  }else{
    printf("ERROR! Archivo vacio");
  }
  fclose(f);
  
}
