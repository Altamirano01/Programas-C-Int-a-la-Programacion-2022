//Algoritmo problema 3 practico 5
#include<stdio.h>
#include<string.h>
int anio;
char mensaje[20];
char *Bisiesto(int a){
    if((a % 4 == 0) && ((a % 100 != 0) || (a % 400 == 0))){
        return("Bisiesto");
    }else{
        return("NO bisiesto");
    }
}
void main(){
    printf("Ingrese un año: ");
    scanf("%d", &anio);
        strcpy(mensaje, Bisiesto(anio));
    printf("%s", mensaje);    
}