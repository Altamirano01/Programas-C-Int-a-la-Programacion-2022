//Algoritmo problema 8 practico 3
#include<stdio.h>
int num;
char *mensaje;
int main(){
    printf("Ingrese un numero Entero: ");
    scanf("%d", &num);
        if((num % 2 == 0) && !(num % 3 == 0)){
            mensaje = "El numero es multiplo de 2";
        }else if((num % 3 == 0) && !(num % 2 == 0)){
            mensaje = "El numero es multiplo de 3";
        }else if((num % 2 == 0) && (num % 3 == 0)){
            mensaje = "El numero es multiplo de 2 y 3";
        }else if((num % 2 != 0) && (num % 3 != 0)){ //Para indicar distinto se una !=
            mensaje = "El numero no es multiplo ni de 2 ni de 3";
        }
    printf("%s", mensaje);    
    return(0);
}//Ver como hacer para que cuando se ingrese un numero real se rompa el programa, porque por ejemplo si ingreso un 2.5 me tira que es multiplo de 2