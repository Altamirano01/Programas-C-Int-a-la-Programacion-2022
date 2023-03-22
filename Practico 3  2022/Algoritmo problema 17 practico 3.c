//Algoritmo problema 17 practico 3
#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct {
    float x;
    float y;
}TPlano;
TPlano v1, v2;//Vertices opuestos del rectangulo
TPlano c;//Coordenadas del centro del circulo
TPlano p;//Punto cualquiera en el plano
char mensaje[50];
float r;//Radio del circulo
float h;
void main(){
    printf("Ingrese el valor de x del vertice 1: ");
    scanf("%f", &v1.x);
    printf("Ingrese el valor de y del vertice 1: ");
    scanf("%f", &v1.y);
    printf("Ingrese el valor de x del vertice 2: ");
    scanf("%f", &v2.x);
    printf("Ingrese el valor de y del vertice 2: ");
    scanf("%f", &v2.y);
    printf("Ingrese el valor x del centro del circulo: ");
    scanf("%f", &c.x);
    printf("Ingrese el valor y del centro del circulo: ");
    scanf("%f", &c.y);
    printf("Ingrese el valor x del punto en el plano: ");
    scanf("%f", &p.x);
    printf("Ingrese el valor y del punto en el plano: ");
    scanf("%f", &p.y);
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &r);
        h = sqrt(((p.x - c.x) * (p.x - c.x)) + ((p.y - c.y) * (p.y - c.y)));
        if(((p.x >= v1.x) && (p.x <= v2.x)) && ((p.y  <= v2.y) && (p.y >= v1.y)) && (h <= r)){//Ver si la condicion de la h va ahi para hacerla excluyente
            strcpy(mensaje, "El punto es interior al rectangulo");
        }else if(!(((p.x >= v1.x) && (p.x <= v2.x)) && ((p.y  <= v2.y) && (p.y >= v1.y)) && (h <= r))){
            strcpy(mensaje, "El punto es exterior al rectangulo");
          }else if(h <= r){
                    strcpy(mensaje, "El punto es interior al circulo");
          }else if(!(h <= r)){
                    strcpy(mensaje, "El punto es exterior al circulo");
            }else if((((p.x >= v1.x) && (p.x <= v2.x)) && ((p.y  <= v2.y) && (p.y >= v1.y))) && (h <= r)){
                        strcpy(mensaje, "El punto es interior al circulo y al rectangulo");
            }else{
                        strcpy(mensaje, "El punto es exterior al circulo y al rectangulo");
            }
    printf("%s", mensaje);
}//Hace bien el analisis antes de todo negrito, si no despues andas corrigiendo con la compilacion hecha