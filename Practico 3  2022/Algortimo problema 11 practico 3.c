//Algortimo problema 11 practico 3
#include<stdio.h>
int mes;//Meses del año 1..13
int dias;
void main(){
    printf("Ingrese un numero correspondiente a un mes del año: ");
    scanf("%d", &mes);
        if((mes >= 1) && (mes <= 12)){ // ||
            if((mes == 1) ||(mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
                dias = 31;
            }else if((mes == 4) ||(mes == 6) || (mes == 9) || (mes == 11)){
                dias = 30;
            }else if(mes == 2){
                dias = 28;
            }
    printf("La cantidad de dias del mes %d es: %d", mes, dias); 
        }else{
    printf("ERROR! Ese numero no corresponde a ningun mes. ");
        }
}//No se rompe con un numero real.
