//Algortimo problema 16 practico 7
#include<stdio.h>
#define N 4
typedef struct{
    int a[N][N];
    int cantF;
    int cantC;
}TData;
TData numeros;
int suma, suma2;
void Cargar(TData *k){
   int i, j; 
    k->cantF = N;
    k->cantC = N;
     for(i = 0; i < k->cantF; i++){
         for(j = 0; j < k->cantC; j++){
             printf("Ingrese un elemento: ");
             scanf("%i", &k->a[i][j]);
         }
     }
}

void Suma(TData k, int *s){
    int i, j;
    for(i = 0; i < k.cantF / 2; i++){
        for(j = 0; j < (k.cantC / 2) + 1; j++)
            *s = *s + k.a[i][j];
    }
}

void Suma2(TData k, int *d){
   int i, j;
    for(i = 0; i < k.cantF; i++){
        for(j = 0; j <= i; j++)
            *d = *d + k.a[i][j];
    }
}
void ImprimirDiagonal(TData k){
    int i, j;
     printf("La diagonal secundaria es: ");
     j = 0;
     i = N - 1;
        while(j < N &&  i >= 0){//Si uno 1 for para cada var no me lo hace
        printf("%d ", k.a[j][i]);
        j++;
        i--;
        } 
}
void main(){
    Cargar(&numeros);
    Suma(numeros, &suma);
    Suma2(numeros, &suma2);
    printf("La suma 1 es: %i, y la suma 2 es: %i\n", suma, suma2);
    ImprimirDiagonal(numeros);
}