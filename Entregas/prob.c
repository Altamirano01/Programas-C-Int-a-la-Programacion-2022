#include<stdio.h>

typedef struct {
long int ddmmyyyy;
int tmax;
int tmin;
int HUM;
int PNM;
int DV;
int FF;
int PP;
int borrado;
} Tregdiario;
#define M 366
typedef struct TData{
  Tregdiario a[M];
  int cant;
}TData;
TData arreglo;
FILE *f;

Tregdiario registro;


void CargarArreglo(FILE *f, TData *q){
  int i;
  Tregdiario c;
    f = fopen("backup2.dat", "rb");
    i = 0;
    q->cant = 0;
    // NO importa si el registro esta borrado
    while(!feof(f)){
      fread(&c, sizeof(c), 1, f);
      q->a[i].ddmmyyyy = c.ddmmyyyy;
      q->a[i].tmin = c.tmin;
      q->a[i].tmax = c.tmax;
      q->a[i].HUM = c.HUM;
      q->a[i].PNM = c.PNM;
      q->a[i].DV = c.DV;
      q->a[i].FF = c.FF;
      q->a[i].PP = c.PP;
      q->a[i].borrado = c.borrado;
      i++;
      q->cant++;
    }
    fclose(f);
}

void OrdenarBurbuja(TData *q){
  int i, j;
  int aux;
  for(i = 1; i < q->cant; i++){
    for(j = 0; j < q->cant; j++){
      if(q->a[j].PP < q->a[j + 1].PP){
          aux = q->a[j + 1].PP;
          q->a[j + 1].PP = q->a[j].PP;
          q->a[j].PP = aux;
      }
    }
  }
    MostrarA(arreglo);
}


void MostrarA(TData q){
  int i;
  for(i = 0; i < q.cant; i++){
    printf("Fecha: %ld\n", q.a[i].ddmmyyyy);
    printf("Prec: %d\n", q.a[i].PP);
    printf("PNM: %d\n", q.a[i].PNM);
    printf("---------------------------------------------------\n");
  }
}

void main(){
  CargarArreglo(f, &arreglo);
  MostrarA(arreglo);
  OrdenarBurbuja(&arreglo);
  printf("\nMODIFICADO\n");
  MostrarA(arreglo);

}