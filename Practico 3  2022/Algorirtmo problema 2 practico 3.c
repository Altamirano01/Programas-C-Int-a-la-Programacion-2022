//Algoritmo problema 2 practico 3
#include<stdio.h>
float precioUno, precioDos;
float costoEnvioUno, costoEnvioDos;//Agregue una variable con el costo de envio de ambas tiendas para
                                  //si en un futuro los costos cambian
char *mensaje;
void main(){
    printf("Ingrese el precio de una tienda: ");
    scanf("%f", &precioUno);
    printf("Ingrese el costo de envio de esa tienda: ");
    scanf("%f", &costoEnvioUno);
    printf("Ingrese el precio de otra tienda: ");
    scanf("%f", &precioDos);
    printf("Ingrese el costo de envio de la segunda tienda: ");
    scanf("%f", &costoEnvioDos);//Entrada   
        if((precioUno >= 0) && (precioDos >= 0)){ //Agregue un if para que si o si los precios 
                                                 //sean positivos
        precioUno = precioUno + costoEnvioUno;
        precioDos = precioDos + costoEnvioDos;
        if(precioUno <= precioDos){ //Si ambos precios son iguales lo manda a comprar en la primera tienda, porque se supone que es la mas confiable
            mensaje = "Conviene comprar en la primera tienda";
        }else{
            mensaje = "Conviene comprar en la segunda tienda";
        }
    printf("\nEl precio final de la primera tienda es de: %f", precioUno);
    printf("\nEl precio final de la segunda tienda es de: %f", precioDos);
    printf("\n%s", mensaje);
    }else{
        printf("ERROR! El precio no puede ser negativo.");
    }
}