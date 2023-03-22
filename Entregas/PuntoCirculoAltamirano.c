//Facundo Altamirano
#include<stdio.h>
#include<math.h>
#include<string.h>
float h, k; //Puntos del centro del circulo
float x, y; //Coordenadas del punto en el plano
float r;//Radio del circulo
float d;
char mensaje[35];
void main(){
    printf("Ingrese el punto h: ");
    scanf("%f", &h);
    printf("Ingrese el punto k: ");
    scanf("%f", &k);
    printf("Ingrese el punto x: ");
    scanf("%f", &x);
    printf("Ingrese el punto y: ");
    scanf("%f", &y);
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &r);
        d = sqrt(((x - h) * (x - h)) + ((y - k) * (y - k)));
            if(d <= r){
                strcpy(mensaje, "El punto esta dentro del circulo");
            }else{
                strcpy(mensaje, "El punto esta fuera del circulo");
            }
    printf("%s", mensaje);        
}