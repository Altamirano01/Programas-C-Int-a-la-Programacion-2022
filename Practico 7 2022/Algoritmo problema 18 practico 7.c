//Algoritmo problema 18 practico 7
#include<stdio.h>
#define N 3
#define M 3
typedef struct{
    int a[N][M];
    int cantF;
    int cantC;
}TData;
TData matrizA;
TData matrizB;
TData matrizC;
int sumaMatrices;
void CargarA(TData *a){
   int i, j; 
    a->cantF = N;
    a->cantC = N;
    printf("A continuacion ingrese la primera matriz: ");
    printf("\n");
     for(i = 0; i < a->cantF ; i++){
         for(j = 0; j < a->cantC ; j++){
             printf("Ingrese un elemento: ");
             scanf("%i", &a->a[i][j]);
         }
     }
}
void CargarB(TData *b){
   int i, j; 
    b->cantF = N;
    b->cantC = N;
    printf("A continuacion ingrese la segunda matriz: ");
    printf("\n");
     for(i = 0; i < b->cantF ; i++){
         for(j = 0; j < b->cantC ; j++){
             printf("Ingrese un elemento: ");
             scanf("%i", &b->a[i][j]);
         }
     }
}

void SumarAyB(TData a, TData b, TData *c){
    int i, j;
    (*c).cantF = N;
    (*c).cantC = M;
     for(i = 0; i < N; i++){
        for(j = 0 ; j < M; j++){
            (*c).a[i][j] = a.a[i][j] + b.a[i][j];    
        }
     }    
}
void MostrarA(TData a){
    int i, j;
     printf("La matriz A es: ");
     printf("\n");
     printf("\n");
     for(i = 0; i < a.cantF; i++){
         for(j = 0; j < a.cantC; j++){
             printf("%d ", a.a[i][j]);
         }
         printf("\n");
     }
     printf("\n");
}

void MostrarB(TData b){
    int f, g;
     printf("La matriz B es: ");
     printf("\n");
     printf("\n");
     for(f = 0; f < b.cantF; f++){
         for(g = 0; g < b.cantC; g++){
             printf("%d ", b.a[f][g]);
         }
         printf("\n");
     }
     printf("\n");
}

void MostrarC(TData c){    
    int x, z;
     printf("La matriz C es: ");
     printf("\n");
     printf("\n");
     for(x = 0; x < c.cantF; x++){
         for(z = 0; z < c.cantC; z++){
             printf("%d ", c.a[x][z]);
         }
         printf("\n");
     }
     printf("\n");
}//No hace falta hacer una accion para cada matriz, puedo hacerlo solo en una 
void main(){
    CargarA(&matrizA);
    CargarB(&matrizB);
    SumarAyB(matrizA, matrizB, &matrizC);
    MostrarA(matrizA);
    MostrarB(matrizB);
    MostrarC(matrizC);
}