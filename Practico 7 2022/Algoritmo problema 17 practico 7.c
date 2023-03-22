//Algoritmo problema 17 practico 7
#include<stdio.h>
#define N 4
#define M 4
typedef struct{
    int a[N][M];
    int cantF;
    int cantC;
}TData;
TData numeros;
int sumaTotal;
void Cargar(TData *k){
   int i, j; 
    k->cantF = N;
    k->cantC = N;
     for(i = 0; i < k->cantF ; i++){
         for(j = 0; j < k->cantC ; j++){
             printf("Ingrese un elemento: ");
             scanf("%i", &k->a[i][j]);
         }
     }
}
int EsLimite(int a, int b){
 if((a == 1 || a == N) ||(b == 1 || b == M)){//Puede haber un error en la condicion
    return(0);
 }else{
    return(1);
 }
}
void Sumatoria(TData k, int *s){
 int i, j;
 *s = 0;
 for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
        printf("\nLa suma temp es: %d", *s);
        if(EsLimite(i, j) == 0){
            *s = *s + k.a[i][j];
        }else{
            *s = *s - k.a[i][j];
        }
    }    
 } 
  printf("\nLa suma de la cascara y corazon de la matriz es: %d", *s);//Ver por que me da siempre 2(Con la prueba q me dieron en el practico)
}
void Mostrar(TData n){
    int i, j;
    printf("La matriz ha sido cargada y es: \n");
    for(i = 0; i < n.cantF; i++){
        for(j = 0; j < n.cantC; j++){
            printf("%d ", n.a[i][j]);
        }
        printf("\n");
    }
}
void main(){
    Cargar(&numeros);
    Mostrar(numeros);
    Sumatoria(numeros, &sumaTotal);
}