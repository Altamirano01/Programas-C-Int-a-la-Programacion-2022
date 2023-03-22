//Algoritmo problema 9 practico 3
//Altamirano Facundo
#include<stdio.h>
#include<string.h>
int indicio;
char sint1[30];
char sint2[30];
char sint3[30];
char sint4[30];
char sint5[30];
char respuesta[50];
void main(){
    printf("Ingrese el sintoma 1: ");
    fgets(sint1, 30, stdin); //fgets(nombre_cadena, numero_caracteres, FILE); FILE es de donde se obtiene el archivo, en este caso de la entrada por eso es stdin
    printf("Ingrese el sintoma 2: ");
    fgets(sint2, 30, stdin);
    printf("Ingrese el sintoma 3: ");
    fgets(sint3, 30, stdin);
    printf("Ingrese el sintoma 4: ");
    fgets(sint4, 30, stdin);
    printf("Ingrese el sintoma 5: ");
    fgets(sint5, 30, stdin);
        indicio = 0;
        if(strcmp(sint1, "tos") == 0){
            indicio = 1;
        }else{
            indicio = 0;
        }
        if(strcmp(sint2, "estornudo") == 1){
            if(strcmp(sint3, "fiebre") == 0){
                indicio = 1;
            }else{
                indicio = 0;
            }
        }else{
            if(strcmp(sint4, "moco") == 0){
                if(strcmp(sint3, "fiebre") == 0){
                    indicio = 2;
                }else{
                    indicio = 0;
                }
            }else{
                indicio = 3;
            }
        }
        if(indicio == 1 && strcmp(sint5, "flema") == 0){
            strcpy(respuesta, "Coronavirus");
        }else if(indicio == 2 && strcmp(sint5, "vomito") == 0){
            strcpy(respuesta, "Gripe");
        }else if(indicio == 3 && strcmp(sint5, "congestion") == 0){
            strcpy(respuesta, "Resfrio");
        }else{
            strcpy(respuesta, "Hasta ahora no parece estar enfermo");
        }
    printf("%s\n", respuesta);
    printf("La cant de indicios es: %d\n", indicio);
}//Estoy poniendo giladas, no se como se escribe un segun en C