//Algoritmo problema 3 practico 7
#include<stdio.h>
#include<string.h>
#define N 30
typedef struct{
    int a[N];
    int cant;
}TBingo;
TBingo bingo;
int num;
int numGanador;
char mensaje[50];
void Bingo(TBingo *b, int n, char* msg){
    int i, aux;
    i = 0;
    aux = 0;
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &b->cant);
     while(i < 30 && aux != n){
        printf("Ingrese un numero: ");
        scanf("%d", &b->a[i]);
        if(b->a[i] == n){
            aux = n;
            strcpy(msg, "Hay un ganador?");
            printf("%s\n", msg);
            strcpy(msg, "SI");
            printf("%s\n", msg);
            b->cant = i + 1;//Esto sirve para luego hacer la accion Mostrar
        }else{
            strcpy(msg, "Hay un ganador?");
            printf("%s\n", msg);
            strcpy(msg, "NO");
            printf("%s\n", msg);
            aux = 0;
        }
        i++;
     }
}
void Mostrar(TBingo b){
    int i;
     printf("Los numeros que se ingresaron fueron: ");
     for(i = 0; i < b.cant; i++){
        printf("%d  ", b.a[i]);
     }
}
void main(){
    printf("Ingrese el numero ganador: ");
    scanf("%d", &numGanador);
     Bingo(&bingo, numGanador, &mensaje);
     Mostrar(bingo);
}