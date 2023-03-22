//Algoritmo problema 19 practico 7
#include<stdio.h>
#define N 10
#define M 10
typedef struct{
    int m[N][M];
    int cantF;
    int cantC;
}TMatriz;
TMatriz matriz;
typedef struct{
    int a[M];
    int cant;
}TVector;
TVector arreglo;
TVector resultado;
void CargarM(TMatriz *m){
   int i, j; 
   printf("Ingrese la cantidad de filas: ");
   scanf("%d", &m->cantF);
   printf("Ingrese la cantidad de Columnas: ");
   scanf("%d", &m->cantC);
    printf("A continuacion ingrese la matriz: ");
    printf("\n");
     for(i = 0; i < m->cantF ; i++){
         for(j = 0; j < m->cantC ; j++){
             printf("Ingrese un elemento: ");
             scanf("%i", &m->m[i][j]);
         }
     }
}
void CargarA(TVector *v){
   int i, j; 
    printf("------------------------------------------------------------------------------\n");
    printf("Ingrese la cantidad de Elementos del arreglo: ");
    scanf("%d", &v->cant);
    printf("A continuacion ingrese el arreglo: ");
    printf("\n");
     for(i = 0; i < v->cant ; i++){
        printf("Ingrese un numero: ");
        scanf("%i", &v->a[i]);
     }
}
void Producto(TMatriz m, TVector v, TVector *r){
    int i, j;
     if(v.cant == m.cantC){
        for(i = 0; i < m.cantF; i++){
            r->a[i] = 0;
            for(j = 0; j < m.cantC; j++){
                r->a[i] = (m.m[i][j] * v.a[j]) + (r->a[i]);
            }
        }
     }else{
        
        printf("\nNo se puede multiplicar. La cantidad de columnas es distinta. \n");
     }
     r->cant = m.cantC;
}
void MostrarM(TMatriz m){    
    int x, z;
     printf("------------------------------------------------------------------------------\n");
     printf("La matriz es: ");
     printf("\n");
     for(x = 0; x < m.cantF; x++){
         for(z = 0; z < m.cantC; z++){
             printf("%d ", m.m[x][z]);
         }
         printf("\n");
     }
}
void MostrarA(TVector v){
    int i;
    printf("------------------------------------------------------------------------------\n");
    printf("El arreglo cargado es: ");
    printf("\n");
     for(i = 0; i < v.cant; i++){
        printf("%d  ", v.a[i]);
     }
     printf("\n");
}
void MostrarC(TVector r){
    int i;
    printf("------------------------------------------------------------------------------\n");
    printf("El arreglo con el producto entre la matriz y el vector es: ");
    printf("\n");
     for(i = 0; i < r.cant; i++){
        printf("%d ", r.a[i]);
     }
}
void main(){
    CargarM(&matriz);
    CargarA(&arreglo);
    Producto(matriz, arreglo, &resultado);
    MostrarM(matriz);
    MostrarA(arreglo);
    MostrarC(resultado);
}