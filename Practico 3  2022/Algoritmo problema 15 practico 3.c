//Algoritmo problema 15 practico 3
#include<stdio.h>
char res1, res2, res3;
int puntaje;
void main(){
    puntaje = 0;
    printf("Ingrese la primera respuesta: ");//Las cadena no se comparar asi, luego buscar como hacerlo
    scanf("%s", &res1);
        if(res1 == "Donatello"){
            puntaje = puntaje + 100;
        }else{
            puntaje = puntaje + 0;
        }
    printf("Ingrese la segunda respuesta: ");
    scanf("%s", &res2);
        if(res2 == "La Piedad"){
            puntaje = puntaje + 100;
        }else{
            puntaje = puntaje + 0;
        }
    printf("Ingrese la tercera respuesta: ");
    scanf("%s", &res3);
        if(res3 == "Rafael"){
            puntaje = puntaje + 100;
        }else{
            puntaje = puntaje + 0;
        }
    printf("El puntaje total es: %d", puntaje);    
}
