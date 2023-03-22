//Algoritmo problema 9 practico 5
#include<stdio.h>
float a, b, p, q;
int res;//Tipo logico en el analisis
int Plano(float c, float d, float e, float f){
    if(f == e * c + d){ 
        return(1);
    }else{
        return(0);
    }
}
void main(){
    printf("Ingrese el a de la recta: ");
    scanf("%f", &a);
    printf("Ingrese el b de la recta: ");
    scanf("%f", &b);
    printf("Ingrese el x del punto: ");
    scanf("%f", &p);
    printf("Ingrese el y del punto: ");
    scanf("%f", &q);
     res = Plano(a, b, p, q);
    printf("Si el punto pertenece a la recta entonces el valor debe ser 1, caso contario es cero.\n");
    printf("El valor es: %d", res);
}