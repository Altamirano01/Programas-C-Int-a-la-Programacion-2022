//Algoritmo problema 5 practico 4
#include<stdio.h>
#include<string.h>
typedef struct {
    char mes[20];
    float mm;
}TLluvia;
TLluvia mes;
int i;
float aux, aux2;
char mayor[20];
char mesMenor[20];
void main(){
    i = 1;
    aux = 0;
    aux2 = 0;
    do{
    printf("Ingrese un mes: ");
    fgets(mes.mes, 20, stdin);
    printf("Ingrese la cantidad de lluvia caida en mm de ese mes: ");
    scanf("%f", &mes.mm);
        if(mes.mm >= aux){
            aux = mes.mm;//guarda la cant de mm del mes que mas llovio
            strcpy(mayor, mes.mes);//Copia el nombre del mes que mas llovio y lo guarda
        }else if(mes.mm < aux2){
            aux2 = mes.mm;
            strcpy(mesMenor, mes.mes);
        }
    i++;    
    }while(!(i <= 12));    
    printf("El mes en que mas llovio es: %s con %fmm", mayor, aux);
    printf("El mes en que menos llovio es: %s con %fmm", mesMenor, aux2);
}//Ni idea pa