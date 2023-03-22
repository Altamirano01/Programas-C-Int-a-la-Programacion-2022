//Algoritmo problema 8 practico 2
#include<stdio.h>
float donacion;
float administracion, cardiologia, neonatologia, terapiaIntensiva;
void main(){
    printf("Ingrese el monto total de dinero que han donado: ");
    scanf("%f", &donacion);//Entrada
    administracion = donacion * 0.7;
    cardiologia = donacion * 0.3;
    neonatologia = cardiologia * 0.7;
    terapiaIntensiva = neonatologia * 0.8;
    cardiologia = cardiologia - neonatologia;
    neonatologia = neonatologia - terapiaIntensiva;//Acciones
    printf("El dinero de la donacion ha sido repartido en las diferentes dependencias: ");
    printf("\nEl dinero destinado para Administracion es: %f", administracion);
    printf("\nEl dinero destinado para Cardiologia es: %f", cardiologia);
    printf("\nEl dinero destinado para Neonatologia es: %f", neonatologia);
    printf("\nEl dinero destinado para Terapia Intensiva es: %f", terapiaIntensiva);//Salida
}