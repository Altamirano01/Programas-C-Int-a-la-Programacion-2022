//Algoritmo problema 5 practico 6
#include<stdio.h>
typedef struct{
    float x;
    float y;
}TPunto;
TPunto a;
TPunto b;
void CargaPunto(TPunto *c, TPunto *d){
    printf("Ingrese el X del primer punto: ");
    scanf("%f", &c.x);
    printf("Ingrese el Y del primer punto: ");
    scanf("%f", &c.y);
    printf("Ingrese el X del segundo punto: ");
    scanf("%f", &d.x);
    printf("Ingrese el Y del segundo punto: ");
    scanf("%f", &d.y);//Ver porque no me deja cargar, me dice que es un puntero
    //Agregar -> creo
}
void main(){
    CargaPunto(&a, &b);
    printf("%.3f %.3f\n", a.x, a.y);
    printf("%.3f %.3f\n", b.x, b.y);
}