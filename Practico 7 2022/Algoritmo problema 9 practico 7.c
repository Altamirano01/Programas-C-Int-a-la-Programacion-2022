//Algoritmo problema 9 practico 7
#include<stdio.h>
#include<string.h>
#define N 200
typedef struct{
    int a[N];//Lo voy a hacer con numeros porque no me deja ingresar un caracter
    int cant;
}TData;
TData frase;
int resultado;//Reemplaza al tipo logico
void CargarFrase(TData *q){
   int i;
    printf("Ingrese la cantidad de letras a cargar: ");
    scanf("%d", &q->cant);
     for(i = 0; i < q->cant; i++){
         printf("Ingrese una letra: ");
         q->a[i] = getchar(); //A partir de aca se pone para ingresar caracter por caracter
         while(getchar() != '\n');          
     } 
}

void Capicua(TData q, int *r){
 int i, j;
  i = 0;
  j = q.cant - 1;
  *r = 0;
    while(i < j){
        i++;
        j = j - 1;
         if(q.a[i] != q.a[j]){
            *r = *r + 1;
         }
    }
     if(*r == 0){
        printf("Capicua. ");
     }else{
        printf("No Capicua. ");
     }
    
}

void main(){
    CargarFrase(&frase);
    Capicua(frase, &resultado);
    
}