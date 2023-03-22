//Algoritmo problema 19 practico 3
#include<stdio.h>
typedef struct{
    int dia;
    int mes;
    int year;
}TFecha;
TFecha fecha;
int bisiesto;
//TFecha diaSig;// Capaz que lo haga mostrandolo directamente por que no se como se asignaria a esta variable el formato dd/mm/aaaa
void main(){
    printf("Ingrese una fecha a continuacion en formato dd/mm/aaaa: ");
    printf("\nIngrese el dia: ");
    scanf("%d", &fecha.dia);
    printf("Ingrese el mes: ");
    scanf("%d", &fecha.mes);
    printf("Ingrese el año: ");
    scanf("%d", &fecha.year);
        //Voy a copiar el algoritmo del problema 18 que determina si un año es bisiesto o no
        if((fecha.year % 4 == 0) && (fecha.year % 100 != 0)){
            bisiesto = 1;
        }else if(!(fecha.year % 4 == 0) && (fecha.year % 100 != 0)){
            bisiesto = 0;
        }else if((fecha.year % 100 == 0) && (fecha.year % 400 == 0)){
            bisiesto = 1;
        }
        if((fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10) && (fecha.dia == 31)){
            fecha.dia = 1;
            fecha.mes = fecha.mes + 1;
        }else if((fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10) && (1 <= fecha.dia < 31)){
            fecha.dia = fecha.dia + 1;
        }else if((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && (fecha.dia == 30)){
            fecha.dia = 1;
            fecha.mes = fecha.mes + 1;
        }else if((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && (1 <= fecha.dia < 30)){
            fecha.dia = fecha.dia + 1;
        }else if(fecha.mes == 2 && (bisiesto == 1)){
                if(fecha.dia == 29){
                    fecha.dia = 1;
                    fecha.mes = fecha.mes + 1;
                }else if(1 <= fecha.dia < 29){
                    fecha.dia = fecha.dia + 1;
                }
        }else if(fecha.mes == 2 && (bisiesto == 0)){
                if(fecha.dia == 28){
                    fecha.dia = 1;
                    fecha.mes = fecha.mes + 1;
                }else if(1 <= fecha.dia < 28){
                    fecha.dia = fecha.dia + 1;
                }                

        }else if(fecha.mes == 12 && fecha.dia == 31){
            fecha.dia = 1;
            fecha.mes = 1;
            fecha.year = fecha.year + 1;
        }else if(fecha.mes == 12 & 1 <= fecha.dia < 31){
            fecha.dia = fecha.dia + 1;
        }
    printf("Se ha calculado el dia siguiente: ");
    printf("%d/%d/%d", fecha.dia, fecha.mes , fecha.year);
}