//Algoritmo problema 13 practico 7
#include<stdio.h>
#define N 200
typedef struct{
    int a[N];
    int cant;
}TData;
TData enteros;
int num;
void Cargar(TData *q){
   int i; 
    printf("Ingrese la cantidad de Elementos: ");
    scanf("%i", &q->cant);
     for(i = 0; i < q->cant; i++){
             printf("Ingrese un elemento: ");
             scanf("%i", &q->a[i]);
         }
}
void Insertar(TData *q, int n){
    int i, aux;
    for(i = 0; i < q->cant; i++){
            if(q->a[i] > n){
                aux = q->a[i];
                q->a[i] = n;
                n = aux;
                q->a[q->cant] = n;
        }
    }
}//No funciona para 1 elemento
void Mostrar(TData q){
    int i;
     for(i = 0; i < q.cant; i++){
            printf("%i", q.a[i]);
        }
}
void main(){
    printf("Ingrese un nuevo numero: ");
    scanf("%i", &num);
    Cargar(&enteros);
    Insertar(&enteros, num);
    Mostrar(enteros);
}