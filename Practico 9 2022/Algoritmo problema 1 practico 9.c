//Algoritmo problema 1 practico 9

//all La lista inicial es: 11-20-25-14
//all La lista que quiero que tenga al final es:  11-20-3-29-14

#include<stdio.h>
#include<stdlib.h>//En esta biblioteca esta malloc

//Lexico
typedef struct TNodo{
    int info;
    struct TNodo *next;//Como es un puntero agrego el aterisco
}TNodo;//TNodo= <info Є entero, next Є puntero a TNodo>

struct TNodo *q, *r, *s, *t, *p;//q, r, t, s, p Є puntero a TNodo
int i;

//Accion para Cargar la lista

//Accion para Mostrar la lista



//Inicio
int main(){//Ver porque me tira error cuando uso void main()
	q = NULL;
	r = NULL; 
	s = NULL;
	t = NULL;
	p = NULL;
	q = (TNodo *)malloc(sizeof(struct TNodo *));
	q->info = 11;
	q->next = NULL;
	r = (TNodo *)malloc(sizeof(struct TNodo *));
	r->info = 20;
	r->next = q->next;
	q->next = r;
	s = q->next;
	r = (TNodo *)malloc(sizeof(struct TNodo *));
	r->info = 25;
	r->next = s->next;
	s->next = r;
	s = r;
	r = (TNodo *)malloc(sizeof(struct TNodo *));
	r->info = 14;
	r->next = s->next;
	s->next = r;
	i = 0;
	r = q;
	printf("\nLista Cargada: ");////Lista inicial
	while(i < 4){
		printf(" %d ->", r->info);
		r = r->next;
		i++;
	}
	//Hasta aca es la carga del primero al ultimo
	r = q;
	r = r->next;
	t = r->next;
	s = (TNodo *)malloc(sizeof(struct TNodo *));
	s->info = 3;
	s->next = r->next;
	r->next = s;
	p = t;
	t->info = 29;
	//Hasta aca son las acciones que da en la practica
	r = q;//Vuelvo al primer lugar a r para imprimir en orden
	i = 0;
	printf("\nLista Modificada: ");////lista Final
	while(i < 5){
		printf(" %d ->", r->info);
		r = r->next;
		i++;
	}
}//! Ahora tengo que ver comoo meter en una accion modular el ciclo de carga e impresion de la lista