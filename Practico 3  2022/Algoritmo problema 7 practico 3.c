//Algortimo problema 7 practico 3
#include<stdio.h>
float t1, t2, t3;
void main(){
    printf("Ingrese el tiempo del nadador 1: ");
    scanf("%f", &t1);
    printf("Ingrese el tiempo del nadador 2: ");
    scanf("%f", &t2);
    printf("Ingrese el tiempo del nadador 3: ");
    scanf("%f", &t3);
        if(t1 <= t2 && t2 <= t3 && t1 <= t3){
            printf("El orden de los tiempos es: %f %f %f", t1, t2 , t3);
        }else if(t1 <= t3 && t3 <= t2 && t1 <= t2){
            printf("El orden de los tiempos es: %f %f %f", t1, t3 , t2);            
        }else if(t2 <= t3 && t3 <= t1 && t2 <= t1){
            printf("El orden de los tiempos es: %f %f %f", t2, t3 , t1);  
        }else if(t2 <= t1 && t1 <= t3 && t2 <= t3){
            printf("El orden de los tiempos es: %f %f %f", t2, t1 , t3);  
        }else if(t3 <= t2 && t2 <= t1 && t3 <= t1){
            printf("El orden de los tiempos es: %f %f %f", t3, t2 , t1);
        }else if(t3 <= t1 && t1 <= t2 && t3 <= t2){
            printf("El orden de los tiempos es: %f %f %f", t3, t1 , t2);
        }
}//Si ingreso cualquier gilada menos un real no se rompe el programa :(

