//Algoritmo problema 8 practico 6
#include<stdio.h>
float px, py;
float coefa, coefb;
int res;
void Recta(float *dA, float *dB){
    printf("Ingrese el coeficiente a: ");
    scanf("%f", &*dA);
    printf("Ingrese el coeficiente b: ");
    scanf("%f", &*dB);
}
void Punto(float *ex, float *ey){
    printf("Ingrese el x del punto: ");
    scanf("%f", &*ex);
    printf("Ingrese el y del punto: ");
    scanf("%f", &*ey);
}
void DondeEsta(float cx, float cy, float rA, float rB, int *respuesta){
    if(cy == rA * cx + rB){
        *respuesta == 1;
    }else{
        *respuesta == 0;
    }
}
void main(){
    Recta(&coefa, &coefb);
    Punto(&px, &py);
    DondeEsta(px, py, coefa, coefb, &res);
    if(res == 1){
        printf("El punto pertenece a la recta.");
    }else{
        printf("El punto no pertenece a la recta.");
    }
}//Para meter un tipo nuevo en una accion del Tipo TAlgo necesito poner d->x