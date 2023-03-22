//Algoritmo problema 4 practico 10
#include<stdio.h>
char c;
FILE* f;
int igu, dist;

//Acciion para crear un archivo desde cero
void CrearArchivo(FILE* *g){//Ver como se escribe un parametro del tipo resultado y dato resultado
  char h;
  int i;
  f = fopen("secu.txt", "w");//Lo tengo que hacer con modo de apertura agregar al final, pero lo pongo asi para que borre los archivos pasados
  //allAl nombre el archivo lo puedo meter en una entrada para que la accion sea reutilizable
    for(i = 0; i <= 10; i++){
      printf("Ingrese un caracter: ");
      scanf("%c", &h);
      getchar();
      fputc(h, *g);
    }
  fclose(f);
}

//Accion para ver la cantidad de elementos que son iguales a un caracter que ingrese
void Iguales(char c, FILE* f, int *d){
  char h;
    //Recorro todo el archivo y voy guardando lo que obtengo en una variable
    while(!(feof(f))){
      h = fgetc(f);
      if(c == h){
        //Suma en uno la cantidad si los caracteres son iguales
        d++;
      }
    }
}

//Devuelve la contidad de caracteres del archivo que son iguales al caracter que ingrese
void Distintos(char c, FILE* f, int *a){
  char h;
    while(!feof(f)){
      h = fgetc(f);//Con esto se obtiene caracter por caracter
      if(h == c){
        a++;
      }
    }
}

void main(){
  CrearArchivo(&f);
  igu = 0;
  dist = 0;
  printf("Ingrese el caracter para buscarlo en el archivo: ");
  scanf("%c", &c);
  getchar();
  f = fopen("secu.txt", "r");
  Iguales(c, f, &igu);
  Distintos(c, f, &dist);
  printf("La cantidad de elementos iguales a '%c' es: %d\n", c, igu);
  printf("La cantidad de elementos distintos a '%c' es: %d\n", c, dist);
  fclose(f);
}