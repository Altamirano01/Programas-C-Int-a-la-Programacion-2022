//Algoritmo Trabajo Practico Integrador
#include<stdio.h>
#include<string.h>
#include<stdbool.h>//Libreria para tipos logicos
#define N 1000
typedef char Cadena[31];
typedef struct{
    Cadena a[N];
    int cant;
}TLista;
TLista lista;//Declaracion arreglo
Cadena nuevoApellido;//Nuevo apellido a insertar
Cadena encontrarApellido;
Cadena buscarApellido;
char preg, preg2;//Auxiliar para interactuar con el usuario
void CargarLista(TLista *q){
    int i;
     printf("Ingrese la cantidad de apellidos que va a ingresar: ");
     scanf("%d", &q->cant);
     for(i = 0; i < q->cant; i++){
        printf("Ingrese un Apellido: ");
        scanf("%s", q->a[i]);
     }
}//Accion para llenar el arreglo
bool Llena(TLista q){
    if(q.cant == 1000){
        return true;
    }else{
        return false;
    }
}//Funcion para ver si la lista esta llena
bool Vacia(TLista q){
    if(q.cant == 0){
        return true;
    }else{
        return false;
    }
}//Funcion para ver si la lista esta vacia
void InsertarApellido(TLista *q, Cadena nuevApe){
    if(Llena(*q) != true){
        q->cant++;
        strcpy(q->a[q->cant], nuevApe);
        printf("SE HA INSERTADO UN NUEVO APELLIDO.\n");
    }else{
        printf("ERROR LA LISTA ESTA LLENA.\n");
    }
}//Accion para insertar un nuevo apellido al final de la lista
void SuprimirUno(TLista *q, Cadena lastname){
    int i;
    i = 0;
    if(Vacia(*q) != true){
        while(i < q->cant){
            if(strcmp(q->a[i], lastname) == 0){
            strcpy(q->a[i], q->a[i + 1]);
            q->cant = q->cant - 1;
        }
        i++;
        }
        printf("APELLIDO BORRADO.\n");
    }else{
        printf("ERROR LA LISTA ESTA VACIA. \n");
    }
}//Accion para suprimier el primer apellido de la lista
void MostrarLista(TLista q){
    int i;
     if(Vacia(q) == false){
        printf("LISTA DE APELLIDOS:\n");
     for(i = 0; i < q.cant; i++){
        printf("%s\n", q.a[i]);
     }
     printf("\n");
     }else{
        printf("NADA QUE MOSTRAR, LA LISTA ESTA VACIA. ");
     }
}//Accion para mostrar la lista completa
void EncontrarUno(TLista l, Cadena encontrar){
    int i;
     for(i = 0; i < l.cant; i++){
        if(strcmp(l.a[i], encontrar) == 0){
            printf("SE HA ENCONTRADO EL APELLIDO, ESTA EN LA POSICION: %d\n", i);
        }else if(i = l.cant){
            printf("EL APELLIDO NO FUE ENCONTRADO.\n");
        }
     }
}//Hay que cambiarlo a funcion, por que es lo que pide el practico
//Accion que permite encontrar uno en la lista
//void HayRepetidos(TLista l){
    //int i;
    // for()
//Ver que quiere bien la funcion, si a partir de dos apellidos ingresados diga si estan en el arreglo o si
//a partir de un apellido mire si esta en el arreglo
void main(){
    CargarLista(&lista);
     printf("Quiere insertar un nuevo apellido? S/N: ");
     while(getchar() != '\n');
     preg = getchar();
     if(preg == 's'){
        printf("Ingrese el nuevo apellido que quiere cargar: ");
        scanf("%s", &nuevoApellido);
        InsertarApellido(&lista, nuevoApellido);
     }else{
        printf("\n");
     }
     printf("Quiere suprimir un apellido? S/N: ");
     while(getchar() != '\n');
     preg2 = getchar();
      if(preg2 == 's'){
         printf("Ingrese un apellido: ");
         scanf("%s", &buscarApellido);
         SuprimirUno(&lista, buscarApellido);
      }else{
         printf("\n");
       }
     printf("Desea encontrar un apellido? S/N: ");
     while(getchar() != '\n');
     preg2 = getchar();
     if(preg2 == 's'){
        printf("Ingrese el apellido: ");
        scanf("%s", &encontrarApellido);
        EncontrarUno(lista, encontrarApellido);
     }else{
        printf("\n");
     }
    MostrarLista(lista);
}