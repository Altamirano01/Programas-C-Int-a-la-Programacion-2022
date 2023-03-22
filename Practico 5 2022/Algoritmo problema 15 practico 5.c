//Algoritmo problema 15 practico 5
#include<stdio.h>
#include<string.h>
int jugador;
char mensaje [50];
//No puedo poner un tipo enumerado con las palabras oro basto copa espada, entonces tengo que hacer un if comparando las cadenas restringiendo para que no ingrese nada extra;o
typedef struct{
     int num;
     char palo[10];
}TCarta;
TCarta carta1;
TCarta carta2;
TCarta carta3;
int Truco(TCarta c1, TCarta c2, TCarta c3){
    if(strcmp(c1.palo, c2.palo) == 0 && strcmp(c2.palo, c3.palo)== 0){
        return(1);
    }else if(strcmp(c1.palo, c2.palo) == 0 && strcmp(c2.palo, c3.palo) == 1){
        return(2);
    }else if(strcmp(c1.palo, c3.palo) == 0 && strcmp(c3.palo, c2.palo) == 1){
        return(2);
    }else if(strcmp(c1.palo, c2.palo) == 1 && strcmp(c2.palo, c3.palo) == 0){
        return(2);
    }else if(strcmp(c1.palo, c2.palo) == 1 && strcmp(c3.palo, c2.palo) == 1){//Hace falta hacer todas excluyentes?
        return(0);
    }
}
void main(){
    printf("Ingrese el numero de la primera carta: ");
    scanf("%d", &carta1.num);
    printf("Ingrese le palo de la primer carta: \n"); 
    fgets(carta1.palo, 10, stdin);
    printf("Ingrese el numero de la segunda carta: ");
    scanf("%d", &carta2.num);
    printf("Ingrese el palo de la segunda carta: \n");
    fgets(carta2.palo, 10, stdin);
    printf("Ingrese el numero de la tercer carta: ");
    scanf("%d", &carta3.num);
    printf("Ingrese el palo de la tercer carta: \n");
    fgets(carta3.palo, 10, stdin);
     jugador = Truco(carta1, carta2, carta3);
     if(jugador == 0){
         strcpy(mensaje, "Tiene tres cartas distintas.");
     }else if(jugador == 1){
         strcpy(mensaje, "Tiene Flor.");
     }else if(jugador == 2){
         strcpy(mensaje, "Tiene Envido");
     }
    printf("%s", mensaje);
}//Tengo que hacer una iteracion para la entrada de los numeros de las cartas restringuiendo de 1 a 7 y de 10 a 12, por que si no puede ingresar cualquier cosa