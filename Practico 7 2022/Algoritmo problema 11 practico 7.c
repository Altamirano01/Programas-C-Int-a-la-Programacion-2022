//Algoritmo problema 11 practico 7
#include<stdio.h>
#define N 100
typedef struct{
    int a[N];
    int cant;
}TArreglo1;
TArreglo1 arregloA;
typedef struct{
    int b[N];
    int cant;
}TArreglo2;
TArreglo2 arregloB;
int cantElemCopiados;
void CargarA(TArreglo1 *q){
    int i;
     printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &q->cant);
    for(i = 0; i < q->cant; i++){
        printf("Ingrese un elemento: ");
        scanf("%d", &q->a[i]);
    }
}
void Copiar(TArreglo1 q, TArreglo2 *b, int *cant){
    int i, j, c;
    c = 0;
    *cant = 0;
     i = 0;
        for(i = 0; i < q.cant; i++){
            for(j = 0;j < q.cant; j++){
                 if(q.a[i] != b->b[j]){
                    b->b[c] = q.a[i];
                    c++;
                 }
            }
        }
    b->cant = q.cant;
}
void MostrarAmbos(TArreglo1 q, TArreglo2 b, int cant){
    int i, j;
     printf("\nEl primer arreglo es: ");
     for(i = 0; i < q.cant; i++){
        printf("%d", q.a[i]);
     }//Para mostrar arreglo A
     printf("\nEl segundo arreglo es: ");
     for(j = 0; j < q.cant; j++){
        printf("%d", b.b[j]);
     }//Para mostrar arreglo B
}
void main(){
    CargarA(&arregloA);
    Copiar(arregloA, &arregloB, &cantElemCopiados);
    MostrarAmbos(arregloA, arregloB, cantElemCopiados);
}


