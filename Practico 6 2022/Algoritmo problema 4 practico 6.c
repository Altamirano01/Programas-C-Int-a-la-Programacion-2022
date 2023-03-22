//Algoritmo problema 4 practico 6
#include<stdio.h>
#include<string.h>
float n1, n2, res;
char c;
void Calculadora(float op, float op2, char b, float *r){//Los parametros resultados y dato-resultado se pasan con el puntero * o con &
 char msg[30];
 if(b == '*'){
     *r = op * op2;
 }else if(b == '+'){
     *r = op + op2; 
 }else if(b == '-'){//Para cadenas es "" y para caracteres es ''
     *r = op - op2;
 }else if(b == '/'){ //Para comparar caracteres se utilizan los signos normales, strcmp es solo para cadenas
     if(op2 > 0 || op2 < 0){
         *r = op / op2;
     }else if(op2 == 0){
         *r = 99999999;
         strcpy(msg, "ERROR.\n");
         printf("%s", msg);//Tengo que poner esto, por que si lo pongo al final con el res, si no es / no va a salir ningun mensaje y salen caracteres varios
     }
 }else if(!((b == '*') && (b == '+') && (b == '+') && (b == '/'))){
     strcpy(msg, "Operador invalido\n");
     printf("%s", msg);
 }
 printf("%.3f", *r);
}
void main(){
    printf("Ingrese el operador: ");
    scanf("%c", &c);//Fgets es solo para cadenas
    //Tuve que ingresar el operador primero que todo, por que si no no me dejaba hacer la operacion
    printf("Ingrese un numero: ");
    scanf("%f", &n1);
    printf("Ingrese otro numero: ");
    scanf("%f", &n2);
    res = 0;
    Calculadora(n1, n2, c, &res);//En la invocacion de debe agregar punteros
}