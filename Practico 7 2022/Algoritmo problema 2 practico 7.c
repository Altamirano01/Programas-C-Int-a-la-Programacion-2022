//Algoritmo problema 2 practico 7
#include<stdio.h>
#define N 100
typedef struct{
    char a[N];
    int cant;
}TClave;
TClave clave;
int voc;

void Cargar(TClave *c){
    int i;
     printf("Ingrese la cantidad de elementos: ");
     scanf("%d", &c->cant);
      for(i = 0; i < c->cant; i++){
        printf("Ingrese un elemento:");
        while(getchar() != '\n');// El while esta va arriba, por que si no no me toma el primer caracter de la frase
        c->a[i] = getchar();
        //Si pongo mal la entrada de caracteres no funciona el algoritmo
      }
}

char EsVocal(TClave a, int b){
    if((a.a[b] == 'A') || (a.a[b] == 'E') || (a.a[b] == 'I') || (a.a[b] == 'O') || (a.a[b] == 'U') || (a.a[b] == 'a') || (a.a[b] == 'e') || (a.a[b] == 'i') || (a.a[b] == 'o') || (a.a[b] == 'u')){
        return(0);  
    }else{
        return(1);
    }
}

void Espia(TClave a, int *v){
 int b;
  b = 0;
  *v = 0;
  while(b < a.cant){
    if(EsVocal(a, b) == 0){
         *v = *v + 1;
    }
    b++;   
  }
 
}
void Mostrar(TClave c){
    int i;
    printf("La frase ingresada es: ");
    for(i = 0; i < c.cant; i++){
        printf("%c", c.a[i]);
    }
} 

void main(){
    Cargar(&clave);
    Espia(clave, &voc);
    printf("La cantidad de vocales de la frase es: %d\n", voc);
    Mostrar(clave);
}