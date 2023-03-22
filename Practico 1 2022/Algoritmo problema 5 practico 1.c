//Algoritmo problema 5 practico 1
#include<stdio.h>
#include<math.h> // Esta libreria tiene la raiz cuadrada, que esta definida en la funcion sqrt
float pX, pY, cX, cY;
float hip;
float r;
char mensaje[19];//Es la cantidad de caracteres mas el caracter nulo: \0
void main(){
    printf("Ingrese el valor del radio del circulo: ");
    scanf("%f", &r);
    printf("Ingrese el valor de pX: ");
    scanf("%f", &pX);
    printf("Ingrese el valor de pY: ");
    scanf("%f", &pY);  
    printf("Ingrese el valor de cX: ");
    scanf("%f", &cX);
    printf("Ingrese el valor de cY: ");
    scanf("%f", &cY);
        hip = sqrt(((pX - cX) * (pX - cX)) + ((pY - cY) * (pY - cY)));
            if (r >= hip) {
                char mensaje[20] = "Dentro del circulo";//Asi se le asigna una frase a la cadena  
                                                        //Esto esta mal, tengo que usar strcpy para asignar algo a una cadena
            }else{
                char mensaje[20] = "Fuera del circulo";//Aca se puede hacer una salida directamente(printf) con el mensaje que quiero dar directamente
    printf("%f", hip);
    printf("%s", mensaje);
}



//Otra forma de hacerlo sin tener problemas con la salida del mensaje: utilizando puntero
//Programa testeado.
#include<stdio.h>
#include<math.h> // Esta libreria tiene la raiz cuadrada, que esta definida en la funcion sqrt
float pX, pY, cX, cY;
float hip;
float r;
char *mensaje;//Hay que agregar un puntero a las cadenas para imprimirlas con printf
void main(){
    printf("Ingrese el valor del radio del circulo: ");
    scanf("%f", &r);
    printf("Ingrese el valor de pX: ");
    scanf("%f", &pX);
    printf("Ingrese el valor de pY: ");
    scanf("%f", &pY);  
    printf("Ingrese el valor de cX: ");
    scanf("%f", &cX);
    printf("Ingrese el valor de cY: ");
    scanf("%f", &cY);
        hip = sqrt(((pX - cX) * (pX - cX)) + ((pY - cY) * (pY - cY)));
            if (r >= hip) {
                mensaje = "El punto esta Dentro del circulo"; 
            }else{
                mensaje = "El punto esta Fuera del circulo";
            }
    printf("%f", hip);
    printf("\n%s", mensaje);
}

//Facundo Altamirano
#include<stdio.h>
#include<math.h>//Para usar raiz
#include<string.h>//Operaciones de cadenas
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
                strcpy(mensaje, "El punto esta fuera del circulo");//Este es para asignar un valor a una variable cadena
            }
    printf("%s", mensaje);        
}