//Algoritmo problema 5 practico 2
#include<stdio.h>
float a, b, c;
float d, e, f, g, r;
float longLineas, areaCesped, areaPista;
float areaCirc, areaCircExt, supRect, perimCirc, areaRectExt;
#define PI 3.14159265359;//Para declarar constantes se utiliza #define <identificador> <valor>
void main(){
    printf("Ingrese el largo de la cancha: ");
    scanf("%f", &a);
    printf("Ingrese el ancho de la cancha: ");   
    scanf("%f", &b);
    printf("Ingrese el ancho de la pista: ");
    scanf("%f", &c);
    printf("Ingrese el largo de la linea vertical del area grande: ");
    scanf("%f", &e);
    printf("Ingrese el largo de la linea horizontal del area grande: ");
    scanf("%f", &d);
    printf("Ingrese el largo de la linea vertical del area chica: ");
    scanf("%f", &g);
    printf("Ingrese el largo de la linea horizontal del area chica: ");
    scanf("%f", &f);
    printf("Ingrese el radio del circulo de mitad de cancha: ");
    scanf("%f", &r); //Entrada de datos
        areaCirc = PI * ((b/2) * (b/2));
        supRect = a * b;
        areaCesped = areaCirc + supRect;
        printf("\nEl area a cubrir con cesped sintetico es de: %f", areaCesped); //Punto A del problema
            areaCircExt = PI * (b + c / 2) * (b + c / 2);
            areaRectExt = b + c * a;
            areaPista = (areaCircExt + areaRectExt) - areaCesped;
            printf("\nEl area a pavimentar para la pista es de: %f", areaPista);//Punto B del problema
                perimCirc = 2 * PI * r;
                longLineas = a * 2 + b * 3 + perimCirc + d * 2 + e * 4 + f * 4 + g * 2;
                printf("\nLa longitud total de las lineas de toda la cancha es de: %f", longLineas);//Punto C del problema              
}
