//Algoritmo problema 2 practico 4
#include<stdio.h>
int n;
int aux;
void main(){
    printf("Ingrese el numero 1: ");
    scanf("%d", &n);
        if(n == 1){
            printf("Los numeros del 1 al 100 divisibles por 2, 4 y 6 simultaneamente son: ");
            do{
                if(n % 2 == 0 && n % 4 == 0 && n % 6 == 0){
                    aux = n;
                }
                    printf("%d", aux);                
                n = n + 1;
            }while(!(n <= 100));
        }else{
            printf("ERROR! El numero ingresado es invalido.");
        }
}