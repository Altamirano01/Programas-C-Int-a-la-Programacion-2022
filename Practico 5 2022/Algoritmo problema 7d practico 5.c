//Algoritmo problema 7d practico 5
#include<stdio.h>
int a, x;
int res;//Es de tipo logico pero devuelve 1 o 0
int Multiplo(int b, int y){
    if(b % y == 0){
        return(1);
    }else{
        return(0);
    }
}
void main(){
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    printf("Ingrese otro numero: ");
    scanf("%d", &x);
     res = Multiplo(a, x);
    printf("Si %d es multiplo de %d entonces devuelve 1, si no devulve 0: %d", a, x, res);
}