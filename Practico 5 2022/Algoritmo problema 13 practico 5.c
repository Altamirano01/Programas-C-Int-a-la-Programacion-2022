//Algoritmo problema 13 practico 5
#include<stdio.h>
float precioCuota, antiguedad, precioPagar;
float Club(float p, float a){
    if(a > 5){
        return(p - (p * 0.08));
    }else{
        return(p);
    }
} 
void main(){
    printf("Ingrese el precio de la cuota: ");
    scanf("%f", &precioCuota);
    printf("Ingrese la antiguedad del socio: ");
    scanf("%f", &antiguedad);//La antiguedad del socio la redondea para arriba, 1.5=2
     precioPagar = Club(precioCuota, antiguedad);
    printf("El valor actual de la cuota es: %.2f\nLa antiguedad del socio es: %.0f\nEl monto a pagar es: %.2f", precioCuota, antiguedad, precioPagar);
}

    
