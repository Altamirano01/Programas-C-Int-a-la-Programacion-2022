//Algoritmo problema 10 practico 7
#include<stdio.h>
#define N 300
typedef struct{
    char a[N];
    int cant;
}TData;
TData frase;
//Funcion para llenar el arreglo
void Cargar(TData *q){
 int k;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &q->cant);
     for(k = 0; k < q->cant; k++){
        printf("Ingrese un elemento: ");
        while(getchar() != '\n');
        q->a[k] = getchar();
     }
}
//Funcion para dar vuelta la palabra
void Espejo(TData *q){//Lo hice con accion, por que con funcion no se puede modificar el entorno
    int i, j;
    char aux;
     i = 0;
     j = q->cant - 1;
    while(i < j ){
        aux = q->a[i];
        q->a[i] = q->a[j];
        q->a[j] = aux;
        i++;
        j = j - 1;
    }
}
//Accion para mostrar la frase modificada
void Mostrar(TData q){
 int i;
    printf("Se dio vuelta la frase, Ahora es: ");
     for(i = 0; i < q.cant; i++){
        printf("%c", q.a[i]);
     }
}
void main(){
    Cargar(&frase);
    Espejo(&frase);
    Mostrar(frase);
}