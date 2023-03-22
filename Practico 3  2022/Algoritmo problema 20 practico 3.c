//Algoritmo problema 20 practico 3
#include<stdio.h>
typedef struct{
    int hora;
    int min;
    int seg;
}THora;
THora hora;
void main(){//Ver los tipos de funciones
    printf("Ingrese las horas: ");
    scanf("%d", &hora.hora);
    printf("Ingrese los minutos: ");
    scanf("%d", &hora.min);
    printf("Ingrese los segundos: ");
    scanf("%d", &hora.seg);
        if(hora.min == 59 && hora.seg == 59){   
            hora.min = 00;
            hora.seg = 00;
            hora.hora = hora.hora + 1;
        }else if(0 <= hora.min < 59 && hora.seg == 59){
            hora.min = hora.min + 1;
            hora.seg = 00;
        }else if(0 <= hora.min < 59 && 1 <= hora.seg < 59){
            hora.min = hora.min + 1;
            hora.seg = hora.seg + 1;
        }
    printf("Se ha sumado un segundo a la hora ingresada:");
    printf("\n%d:%d:%d", hora.hora, hora.min, hora.seg);//Ver como hacer para que imprima la hora en 00:00:00 y no en 0:0:0
}//Ver bien este problema 