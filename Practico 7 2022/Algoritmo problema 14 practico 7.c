//Algoritmo problema 14 practico 7
#include<stdio.h>
#define N 100
typedef struct{
    char a[N];
    int cant;
}TFrase;
TFrase frase;
void CargarFrase(TFrase *c){
    int i;
     printf("Ingrese la cantidad de letras de la frase: ");
     scanf("%d", &c->cant);
      for(i = 0; i < c->cant; i++){
        printf("Ingrese una letra:");
        while(getchar() != '\n');
        c->a[i] = getchar();
      }
}
void EliminarBlancos(TFrase *c){
    int i;
     i = 0;
     while(i < c->cant){
        if(c->a[i] == ' '){
            c->a[i] = c->a[i+1];
            c->cant--;
        }
      i++;  
     }
}//No funciona si la frase empieza con un espacio
void MostrarFrase(TFrase c){
    int i;
    printf("Se han eliminado los espacios en blanco, ahora la frase es: ");
    for(i = 0; i < c.cant; i++){
        printf("%c", c.a[i]);
    }
} 
void main(){
    CargarFrase(&frase);
    EliminarBlancos(&frase);
    MostrarFrase(frase);
}