//Algoritmo problema 9 practico 6
#include<stdio.h>
#include<math.h>
typedef struct{
    float x, y;
}TPunto;
TPunto punto;
typedef struct{
    float x, y;//Coordenadas del punto
    float r;//radio
}TCirculo;
TCirculo circulo;
int respuesta;
void CargarPunto(TPunto *a){
 printf("Ingrese el X del punto: ");
 scanf("%f", &a->x);
 printf("Ingrese el Y del punto: ");
 scanf("%f", &a->y);
}
void CargarCirculo(TCirculo *c){
 printf("Ingrese el X del circulo: ");
 scanf("%f", &c->x);
 printf("Ingrese el Y del circulo: ");
 scanf("%f", &c->y);
 printf("Ingrese el Radio del circulo: ");
 scanf("%f", &c->r);
}
void DondeEsta(TCirculo c, TPunto p, int *res){
float d;
    d = sqrt(((p.x - c.x) * (p.x - c.x)) + ((p.y - c.y) * (p.y - c.y)));
    if(d <= c.r){
        *res = 1;
    }else{
        *res = 0;
    }
}
void main(){
    CargarPunto(&punto);
    CargarCirculo(&circulo);
    DondeEsta(circulo, punto, &respuesta);
    if(respuesta == 1){
        printf("El punto esta dentro del circulo");
    }else{
        printf("El punto esta fuera del circulo");
    }
}