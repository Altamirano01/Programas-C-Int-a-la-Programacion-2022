//Algoritmo problema 4 practico 5
#include<stdio.h>
#include<math.h>
typedef struct{
    float x;
    float y;
}TPunto;
TPunto p1;
TPunto p2;
float d;
float Plano(TPunto a, TPunto b){
    return(sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
void main(){
    printf("Ingrese la x del primer punto: ");
    scanf("%f", &p1.x);
    printf("Ingrese la y del primer punto: ");
    scanf("%f", &p1.y);
    printf("Ingresa la x del segundo punto: ");
    scanf("%f", &p2.x);
    printf("Ingresa la y del segundo punto: ");
    scanf("%f", &p2.y);
     d = Plano(p1, p2);
    printf("La distancia entre los dos puntos en el plano es: %f", d);
}