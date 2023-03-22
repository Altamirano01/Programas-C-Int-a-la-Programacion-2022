//Algoritmo problema 1 practico 10
#include<stdio.h>
#include<stdlib.h>
//Crear el archivo de texto en la carpeta donde compilo
FILE* f;//Se usa para cualquier tipo de archivo
char cadena[5];

int main(){
  f = fopen("test.txt", "r");//Abrir el archivo en el modo indicado
  //Sintaxis: nombInterno = fopen(nombreExterno, modo lectura)
  //r = modo lectura, debe exitir el archivo
  while(!feof(f)){//feof() == EOF()
    fgets(cadena, 3, f);//Lee hasta una linea determinada o hasta el final del archivo
    //Sintaxis: fgets(variable, longitud maxima, nombreinterno)
    //!VER como hacer para que solo lea hasta donde quiera
    printf("%s", cadena);
  }
  fclose(f);//Cerrar el archivo, fclose(nombInterno)
}
