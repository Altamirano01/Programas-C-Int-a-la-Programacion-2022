#include<stdio.h>
#include<stdbool.h>
#define Max 250
typedef struct{
int a[Max];
int cant;
}TData;
TData a;
TData b;

void Cargar(TData *z){
int i;
int t;

	do{
		printf("Ingrese la cantidad de numeros a cargar: ");
		scanf("%d", &t);
	}while(!((t >= 0) && (t <= Max)));
  printf("Ingrese %d numeros: ", t);
	for(i == 0; i < t ; i++){
		scanf("%d", &z->a[i]); //Obtener cada numero 
	}

 z->cant = t;
}

void CargaEnOtro(int q, TData *z){
int i;
bool esta = false;
 i = 0;
	while ((i <= (*z).cant) && (!esta)){
		if(q == (*z).a[i]){
			esta = true;
	}
	i++;	
	}
	if(!esta){
		(*z).a[i] = q;
		(*z).cant = i;
	}
}

void Mostrar(TData z){
int i;
i = 0;
	for(i == 0; i <= z.cant; i++){
		printf("%d", z.a[i]);
 	}	
 printf("%d ", z.cant);
}

//Inicio
void main(){
int i;
Cargar(&a);
 b.cant = 0;
  for(i == 0; i <= a.cant; i++){
	CargaEnOtro(a.a[i], &b);
  }
 Mostrar(b);
} 
