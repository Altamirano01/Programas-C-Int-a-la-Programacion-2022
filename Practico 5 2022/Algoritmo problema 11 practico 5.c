//Algoritmo problema 11 practico 5
#include<stdio.h>
#include<string.h>
#include<stdbool.h>//Esta biblioteca me permite usar booleanos en c
char letra;
bool  vocal, cons;
char mensaje[30];
bool EsMayuscula(char b){
    if(b >= 'A' && b <= 'Z'){//En c deja hacer esto, pero en pseudocodigo tengo que escribir todas las posibilidades
        return(true);
    }else{
        return(false);
    }
}
bool EsMinuscula(char c){
    if(c >= 'a' && c <= 'z'){//En c deja hacer esto, pero en pseudocodigo tengo que escribir todas las posibilidades
        return(true);
    }else{
        return(false);
    }
}
bool EsVocal(char d){
    if(EsMayuscula(d) == true && d == 'A' || d == 'E' || d == 'I' || d == 'O' || d == 'U'){
        return(true);
    }else if(!(EsMayuscula(d) == true && d == 'A' || d == 'E' || d == 'I' || d == 'O' || d == 'U')){
        return(false);
    }else if(EsMinuscula(d) == true &&  d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u'){
        return(true);
    }else if(!(EsMinuscula(d) == true &&  d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u')){
        return(false);
    }
}

bool EsConsonante(char a){
    if(EsVocal(a) == true){
        return(false);
    }else{
        return(true);
    }
}
void main(){
    printf("Ingrese una letra: ");
    scanf("%c", &letra);
     vocal = EsVocal(letra);
     cons = EsConsonante(letra);
     if(vocal == false && cons == false){
         strcpy(mensaje, "No es vocal ni consonante");
     }
    printf("Es vocal: %B\nEs consonante: %B\n %s", vocal, cons, mensaje);  
}//No se como se hace con los return en valores enteros, tendria que volver a hacer el analisis de 0 cambiando el tipo de valor que devuelve la funcion