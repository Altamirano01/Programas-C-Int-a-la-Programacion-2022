//Algoritmo problema 4 practico 7
#include<stdio.h>
#define N 20
typedef struct{
    char a[N];
    int cant;
}TFrase;
TFrase frase;
int cantVocales;
void Cargar(TFrase *q, int *cVoc){
    int i;
     printf("Ingrese la cantidad de caracteres a ingresar: ");
     scanf("%d", &q->cant);
      i = 0;
      cVoc = 0;
       while(i < q->cant && *cVoc != 10){
        printf("Ingrese un caracter: ");
        q->a[i] = getchar() && getchar() != '\n';
         if(q->a[i] == 'a' || q->a[i] == 'e' || q->a[i] == 'i' || q->a[i] == 'o' || q->a[i] == 'u'){
            *cVoc = *cVoc + 1;
                q->cant = i + 1;//Para accion Mostar, creo que no seria autcontenida
         }
        i++; 
       }
}
void Mostrar(TFrase q){
    int i;
    for(i = 0; i <= q.cant; i++){
        printf("%c", &q.a[i]);
    }
}
void main(){
    Cargar(&frase, &cantVocales);
    Mostrar(frase);
}