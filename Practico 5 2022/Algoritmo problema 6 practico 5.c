//Algoritmo problema 6 practico 5
#include<stdio.h>
#include<string.h>
int n;
char mensaje[20];
char *ParImpar(int a){
    if(a == 0){
       return("Es cero."); 
    }else{
        if(a % 2 == 0){
            return("Es par.");
        }else{
            return("Es impar.");
        }
    }
}
void main(){
    printf("Ingrese un numero entero: ");
    scanf("%d", &n);
    strcpy(mensaje, ParImpar(n));
    printf("El numero ingresado %s", mensaje);
}