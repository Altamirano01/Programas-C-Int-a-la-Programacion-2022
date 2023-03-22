//Algoritmo problema 9 practico 4
#include<stdio.h>
float ganancias, perdidas, balance;
float lista;
float i;
void main(){
    lista = 0;
    ganancias = 0;
    perdidas = 0;
    balance = 0;
        while (lista != 999999){
            i = lista;
                if(i >= 0){
                    ganancias = ganancias + i;
                }else{
                    perdidas = perdidas + i;
                }
                balance  = perdidas;//No hay que hacer balance + perdidas porque eso ya esta hecho en linea 16
            printf("Ingrese un numero de la lista: ");
            scanf("%f", &lista);
        }
    printf("El balance del negocio es: %f", balance);    
}