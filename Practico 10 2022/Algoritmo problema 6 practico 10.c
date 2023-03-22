//Algoritmo problema 6 practico 10
#include<stdio.h>
#include<string.h>

typedef char Cadena[80];
Cadena cad;
FILE* f;


//!Ver como hacer para que me separe las frases con el espacio
//Acciion para crear un archivo desde cero
void CrearArchivo(FILE* *g){//Ver como se escribe un parametro del tipo resultado y dato resultado
  Cadena h;
  int i, cant;
  f = fopen("frases.txt", "w");//Lo tengo que hacer con modo de apertura agregar al final, pero lo pongo asi para que borre los archivos pasados
  //allAl nombre el archivo lo puedo meter en una entrada para que la accion sea reutilizable
  printf("Ingrese la cantidad de frases a ingresar: ");
  scanf("%d", &cant);
    for(i = 0; i < cant; i++){
      printf("Ingrese una frase: ");
      scanf("%s", h);
      fputs(h, *g);
    }
  fclose(f);
}

void LeerArchivo(FILE *g, Cadena *cad){
  g = fopen("frases.txt", "r");
  while(!feof(g)){
    fgets(*cad, 80, f);
    printf("%s", *cad);
  }
  fclose(g);
}


void main(){
  CrearArchivo(&f);
  LeerArchivo(f, &cad);
  fclose(f);
}