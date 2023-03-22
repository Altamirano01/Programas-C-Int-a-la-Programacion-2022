//Algoritmo problema 15 practico 7
#include<stdio.h>
#include<string.h>
#define N 2//El ejercicio pide mil, lo hago con 5 para poder testear
typedef struct{
    char a[N];
    int cant;
}TNombres;
TNombres lista;
char otroNombre[20];
char aux;
void Cargar(TNombres *list){
   int i; 
    printf("Ingrese la cantidad de nombres de la lista: ");
    scanf("%i", &list->cant);
     for(i = 0; i < list->cant; i++){
             printf("Ingrese un nombre: ");
             scanf("%s", &list->a[i]);
         }
}
int Vacia(TNombres list){
    if(list.cant == 0){
        return(0);//Esta vacia
    }else{
        return(1);//Tiene al menos un nombre
    }
}
int Llena(TNombres list){
    if(list.cant == N){
        return(0);//Esta llena
    }else{
        return(1);//No esta llena
    }
}
void Insertar(TNombres *list, char *n){
    printf("Ingrese un nuevo nombre: ");
    scanf("%s", &*n);
    if(Llena(*list) == 1){//Si no esta llena
        list->a[list->cant + 1] = *n;
        list->cant = list->cant + 1;   
    }else{
        printf("La lista esta llena, no es posible insertar otro nombre. ");
    }
}
void SuprimirPrimero(TNombres *list){
    if(Vacia(*list) == 1){
        list->a[1] = ' ';
        list->cant = list->cant - 1;
    }
}
void Mostrar(TNombres list){
    int i;
     for(i = 0; i < list.cant; i++){
         printf("%s", list.a[i]);
     }
}
void main(){
    Cargar(&lista);
    printf("Desea insertar otro nombre: S/N ");
    scanf("%c", &aux);
     if(aux == 'S'){
        Insertar(&lista, &otroNombre);
     }
    printf("Desea Suprimir el primer nombre: S/N ");
    scanf("%c", &aux);
     if(aux == 'S'){
        SuprimirPrimero(&lista);
     }
    Mostrar(lista); 
}
