//Algoritmo problema 4 practico 4
//Esta con for
#include<stdio.h>
int n, n1, n2, fibo, i;
void main(){
    printf("Ingrese la cantidad de numeros a imprimir: ");
    scanf("%d", &n);
     n1 = 0;
     n2 = 1;
    if(n == 1){
        printf("%d ", n1);
    }else if(n == 2){
         printf("%d %d ", n1, n2);
    }else if(n > 2){
         printf("%d %d ", n1, n2);
        for(i == 2; i < n; i++){
            fibo = n1 + n2;
            printf("%d ", fibo);
            n1 = n2;
            n2 = fibo;
        }
    }
}

//Fibonacci Repetir
//Facundo Altamirano
#include<stdio.h>
int n;//Cantidad de numeros de la serie 
int n1;// aux1
int n2;// aux 2
int i;//aux 3
int fibo;// resultado
void main(){
	printf("Ingrese la cantidad de numeros de la serie: ");
	scanf("%d", &n);
	 n1 = 0;
	 n2 = 1;
	 if(n == 1){
	 	printf("%d\n", n1);
	 }else if(n == 2){
	 	printf("%d %d\n", n1, n2);
	 }else if(n > 2){
	 	printf("%d\n%d\n", n1, n2);
	 	i = 2;
	 	do{
	 	 fibo = n1 + n2;
	 	 printf("%d\n", fibo);
	 	 n1 = n2;
	 	 n2 = fibo;
	 	 i++; 	
	 	}while(!(i >= n)); 
	 }
}
