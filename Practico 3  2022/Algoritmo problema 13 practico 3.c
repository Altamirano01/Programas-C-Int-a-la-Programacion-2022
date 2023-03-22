//Algortimo problema 13 practico 3 
#include<stdio.h>
float t1, t2, t3; //Tiempo de los nadadores
char *mensaje;
void main(){
    printf("Ingrese el tiempo del nadador 1: ");
    scanf("%f", &t1);
    printf("Ingrese el tiempo del nadador 2: ");
    scanf("%f", &t3);
    printf("Ingrese el tiempo del nadador 3: ");
    scanf("%f", &t3);
        if((t1 < 0) || (t2 < 0) || (t3 < 0)){
            printf("ERROR! Los tiempos no pueden ser negativos.");
        }else{
            if((t1 <= t2) && (t2 <= t3) && (t1 < t3)){
                mensaje = "en Orden Descendente";
            }else if((t1 > t2) && (t2 > t3) && (t3 < t1)){
                mensaje = "en Orden Ascendente";
            }else if(!((t1 > t2) && (t2 > t3) && (t3 < t1)) && !((t1 <= t2) && (t2 <= t3) && (t1 < t3))){
                mensaje = "Desordenados";
            }
        printf("EL tiempo de los nadadores esta %s", mensaje);
        }
}//Ver las condiciones porque las hice como el ogt, volver a hacer el analisis