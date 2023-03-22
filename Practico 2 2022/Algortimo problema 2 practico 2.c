//Algortimo problema 2 practico 2
#include<stdio.h>
int partGanados, partEmpatados, partPerdidos;//Datos
int puntosTotales;//Resultados
void main(){
    printf("Ingrese la cantidad de partidos ganados de su equipo: ");
    scanf("%d", &partGanados);
    printf("Ingrese la cantidad de partidos empatados de su equipo: ");
    scanf("%d", &partEmpatados);  
    printf("Ingrese la cantidad de partidos perdidos de su equipo: ");
    scanf("%d", &partPerdidos); //Entrada de datos
        partGanados = partGanados * 3;
        partEmpatados = partEmpatados * 1;
        partPerdidos = partPerdidos * 0;//No hace falta agregarlo porque no influye en el calculo de puntos totales
        puntosTotales = partGanados + partPerdidos + partEmpatados;
    printf("%d", puntosTotales);//Salida de resultados
}//NOTA: Ver como hacer porque si el usuario ingresa un numero entero negativo el programa no se rompe
//Creo que se puede hacer con una condicion en la que compare ese num(que sea mayor a 0)