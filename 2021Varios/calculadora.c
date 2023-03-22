#include<stdio.h>
float num1;
float num2;
float resultado;
char operador;
char *mensaje;
 void Calcular(float n1, float n2, char op, float *res){
 char *msg;
  if(op == '+'){
	*res = n1 + n2;
  }else if(op == '-'){
	*res = n1 - n2; 
  }else if(op == '*'){
	*res = n1 * n2; 
  }else if((op == '/') & (n2 != 0)){
	*res = n1 / n2;
  }else if((op == '/') & (n2 == 0)){
	*res = 99999;
     msg = "ERROR";
  }
 printf("%s", msg);
}
void main(){
 printf("Ingrese un numero\n");
 scanf("%f", &num1);
 printf("Ingrese otro numero\n");
 scanf("%f", &num2);
 printf("Ingrese un operador [+, -, * o /]\n");
 scanf("%c", &operador);
	if((operador != '+') & (operador != '-') & (operador != '*') & (operador != '/')){
	   mensaje = "El operador ingresado no es valido\n";
	   printf("%s", mensaje);
	}else{
		Calcular(num1, num2, operador, &resultado);
		printf("El resultado de la operacion es: %f\n", &resultado);
	}   
} 