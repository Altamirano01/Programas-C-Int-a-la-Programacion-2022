#include<stdio.h>
#define Max 200
typedef struct{
			char a[Max];
			int cant
				}TData;
				
				
TData frase;
void CargarFrase(TData *f){
   int i == 0;
	printf("Ingrese la cantidad de caracteres que va a ingresar\n");
	scanf("%c", &f->cant);
	 printf("Ingrese cada caracter: \n");
	 while (i < f->cant){
		scanf("%c", &f->a[i]);
		i = i + 1;
	}
}		

void EliminarBlancos(TData *f){
 int i = 0;
 char e = ' '; // Espacio en blanco
 int aux; 
	while ((i <= f->cant) && (f->a[i] != e )){
		i++;
	 }
  aux = i + 1;
	while(aux <= f->cant){
		f->a[aux - 1] = f->a[aux];
		aux = aux + 1;
	}
 f->cant = f->cant - 1;
}	

void MostrarFrase(TData f){
 int i;
  for(i == 0; i <= f.cant; i++){
	printf("%c", f.a[i]);
}
}

void main(){
 CargarFrase(&frase);
 EliminarBlancos(&frase);
 MostrarFrase(frase);
}
				