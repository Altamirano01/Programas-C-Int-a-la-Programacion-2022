//Algoritmo problema 3 practico 3
#include<stdio.h>
int num1, num2; //Ver como puedo hacer para que sea de tipo subrango
               //por que si no tengo que hacer un if
void main(){
    printf("Ingrese un numero entre 0 y 9: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero entre 0 y 9: ");
    scanf("%d", &num2);
       if((num1 >= 0) && (num1 <= 9) && (num2 >= 0) && (num2 <= 9)){
        if(num1 >= num2){
            printf("El mayor numero posible entre %d y %d es: %d%d", num1, num2, num1, num2);
        }else{
            printf("El mayor numero posible entre %d y %d es: %d%d", num1, num2, num2, num1);
        }   
       }else{
           printf("ERROR! El numero ingresado es invalido.");
       } 
}