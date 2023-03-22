//Algoritmo problema 11 practico 6
#include<stdio.h>
typedef struct{ 
    float x, y;
}TPunto;
TPunto p1;
TPunto p3;
TPunto p2;
int res;//Reemplaza el valor logico en el pseudocodigo
void DondeEsta(TPunto a, TPunto b, TPunto c, int *r){
//Aca iria una accion para intercambiar los valores, pero no se si la tengo que declarar en el lexico local o la pongo en el lexico principal
//Voy a probar ponerla en el lexico principal
 void Intercambiar(TPunto pA, TPunto pB){
  TPunto aux;
    if(pA.x > pB.x){
        aux = pA;
        pA = pB;
        pB = aux;
    }
 }
    Intercambiar(a, b);//Invoco la accion
    if((c.x >= a.x && c.x <= b.x && c.y >= a.y && c.y <= b.y) || (c.x <= a.y && c.x <= b.x && c.y >= b.y && c.y >= a.x)){ //Ver las condiciones, por que si ingreso (1;6) me toma como que esta dentro del cuadrado
        *r = 1;
    }else{
        *r = 0;
    }
}

void main(){
    printf("Ingrese el X del primer punto: ");
    scanf("%f", &p1.x);
    printf("Ingrese el Y del primer punto: ");
    scanf("%f", &p1.y);
    printf("Ingrese el X del segundo punto: ");
    scanf("%f", &p2.x);
    printf("Ingrese el Y del segundo punto: ");
    scanf("%f", &p2.y);
    printf("Ingrese el X del tercer punto: ");
    scanf("%f", &p3.x);
    printf("Ingrese el y del tercer punto: ");
    scanf("%f", &p3.y);
        DondeEsta(p1, p2, p3, &res);
        printf("%d", res);
}