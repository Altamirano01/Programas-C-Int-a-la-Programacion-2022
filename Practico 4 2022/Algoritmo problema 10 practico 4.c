//Algoritmo problema 10 practico 4
#include<stdio.h>
#include<string.h>
int n;//Dato
char mensaje[40];//Resultado
int div, i;//Auxiliares
void main(){
    printf("Ingrese un numero que desea ver si es primo: ");
    scanf("%d", &n);
        i = 1;
        div = 0;
        while(i <= n){
            if(n % i ==s 0){
                div = div + 1;
            }else{
                div = div;
            }
            i++;
        }
        if(div == 2){
            strcpy(mensaje, "El numero ingresado es Primo");
        }else{
            strcpy(mensaje, "El numero ingresado no es primo");
        }
    printf("%s", mensaje);
}