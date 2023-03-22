#include<stdio.h>
#define M 100

typedef struct{
  int a[M];
  int cant;
}TData;
TData arreglo;

int i, cont, s;

void CargarNotas(TData *q){
    int i;
     printf("Ingrese la cantidad de notas: ");
     scanf("%d", &q->cant);
     for(i = 0; i < q->cant; i++){
        printf("Ingrese una nota: ");
        scanf("%d", &q->a[i]);
    }
}

int Buscar(TData q, int i, int cont){
  if(i >= q.cant){
    return (-1);
  }else{
    if(q.a[i] == cont){
      return (i);
    }else{
      i++;
      Buscar(q, i, cont);
    }
  }
}

void Intercambiar(int i, int j){
  int aux;
  aux = i;
  i = j;
  j = aux;
}
void Mostrar(TData q){
    int i;
    for(i = 0; i < q.cant; i++){
        printf("%d ", &q.a[i]);
    }
}

void Ordenar(TData q){
  int i, j;
  for ( j = 0; j < q.cant - 1; ++j) {
    for ( i = 0; i < q.cant - j - 1; ++i){
      if (q.a[i] > q.a[i + 1]){
        Intercambiar(q.a[i], q.a[i + 1]);
      }
    }
  }
}

void main(){
  CargarNotas(&arreglo)
  Ordenar(arreglo);
  Mostrar(arreglo);
}





Tregdiario cad;
    *f = fopen(nomExt, "ab");
    printf("Almacenando registro...\n");
    while(!feof(*f) && cad.ddmmyyyy != reg.ddmmyyyy){
      fread(&cad, sizeof(cad), 1, *f);
    }
    if(cad.ddmmyyyy == reg.ddmmyyyy){
      printf("NO SE PUDO AGREGAR, LA FECHA YA EXISTE\n");
    }else{
      fwrite(&reg, sizeof(reg), 1, *f);
    }
    fclose(*f);
    printf("REGISTRO AGREGADO.\n");