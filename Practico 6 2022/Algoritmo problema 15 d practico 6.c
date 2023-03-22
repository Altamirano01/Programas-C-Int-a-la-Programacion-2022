//Algoritmo problema 15 d practico 6
#include<stdio.h>
#include<string.h>
float nota1, nota2, nota3;
char condicion[50];
float CalcularPromedio(float not1, float not2, float not3){
    return((not1 + not2 + not3) / 3);
}
float Menor3Notas(float n1, float n2, float n3){
    if(n1 < n2 && n1 < n3){
        return(n1);
    }else if(n2 < n1 && n2 < n3){
        return(n2);
    }else if(n3 < n1 && n3 < n2 ){
        return(n3);
    }else if(n1 == n2 && n1 == n3 && n3 == n2){
        return(n1);
    }
}
void CondicionAlumno(float a, float b, float c, char *cond){//Ver como se pasan como parametros formales las cadenas
    float p, menorNota;
     p = CalcularPromedio(a, b , c);
     menorNota = Menor3Notas(a, b, c);
     if(menorNota < 4){
         strcpy(cond, "Libre");
     }else if(4 <= menorNota && menorNota < 6 && p < 7){
         strcpy(cond, "Regular");
     }else if(menorNota >= 6 && p >= 7){
         strcpy(cond, "Promocionado");
     }
}
void main(){
    printf("Ingrese la primer nota: ");
    scanf("%f", &nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);
    printf("Ingrese la tercer nota: ");
    scanf("%f", &nota3);
        CondicionAlumno(nota1, nota2, nota3, &condicion);
        printf("%s", condicion);
}//Ahora me pasa siempre libre y no cambie nada 