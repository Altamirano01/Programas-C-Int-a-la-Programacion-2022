// Bibliotecas
// Contienen algunas funciones que utilizaremos
#include <stdio.h> // Sirve para entrada y salida
#include <math.h> // Contiene algunas funciones matematicas, como la Raiz
#include <stdbool.h> // Para el tipo booleano
#include <string.h> // Para manipular cadenas
#include <stdlib.h> // 

// ------------------------------------------------------------------------------------------------------

Hay dos formas de hacer comentarios: 
-con las // Comentario
- /* Comentario */
Ambas tienen su utilidad

// ------------------------------------------------------------------------------------------------------

// Tipos de las variables
// recordar que para el nombre de variables se usa notacion camelCase
// Para constantes se una notacion PascalCase
float numReal; // Tipo real
int numEntero; // Tipo entero
char a; // Tipo caracter
Char cadena [50]; // Tipo cadena, se indica la cantidad maxima de caracteres mas el caracter vacio 
bool verdadero; // Tipo logico, hay que tratarlo de una forma especial 

// Tipo booleano
#define BOOL char
#define FALSE 0
#define TRUE 1

// Tipo registro

typedef char Cadena [100]; // Es un tipa auxiliar para despues no tener problemas de punteros
typedef struct {
  int edad; // Campos
  int dni;
  Cadena nombre;
  Cadena apellido;
  Cadena direccion;
}RegistroPersona; // Nombre

RegistroPersona paciente1, paciente2; // Asignacion

//Contantes
#define <Identificador> <valor>
// Ejemplo
#define Iva 21
#define PI 3.14159265359

// ------------------------------------------------------------------------------------------------------

// Funcion main
// Inicio
int main (){
// Puede ser void main, y no tendriamos que retornar nada
// Nuestro codigo va aqui
return 0;
}

// ------------------------------------------------------------------------------------------------------

// Sintaxis de una entrada de valor de una variable
printf ("Mensaje: "); 
scanf ("%<tipo de dato>", &variableEntrada);
// Ejemplo
printf ("Adios mundo\n"); // El \n sirve para hacer un salto de linea, se usa para separar mensajes
scanf("%d", &variableEntera); // En este caso el %d sirve para enteros


//Si queremos imprimir varias variables en pantalla:
printf("\nLos nuevos valores de los numeros son: A:%d  B:%d", a, b); // Como vemos tenemos que poner tambien %d indicando el tipo de la variable

// ------------------------------------------------------------------------------------------------------

// Tenemos tipos de scanf segun el tipo de la variable:
scanf("%d", &variableEntera); 
scanf("%f", &variableReal); 
scanf("%s", &variableCadena); 
scanf("%c", &variableCaracter); 

// ------------------------------------------------------------------------------------------------------

// Operadores
Matematicos: +, -, *, / 
Ordenamiento: <, >, <=, >=,
== // Igual
!= // Distinto
% // Mod
! // Negacion 
&& // El y logico
|| // El o logico 

// si entonces
if (condiciones) {
  // Acciones 1
}else {
  // Acciones 2
}
// ------------------------------------------------------------------------------------------------------

// si entonces sino, si anidado o segun
if (condiciones 1){

// Acciones 1
}else if (condiciones 2){

// Acciones 2
}else if (condiciones 3){

  //Acciones 3
}

// Ejemplo
#include <stdio.h>
int edad;
void main (){
  printf("Ingresa tu edad: ");
  scanf("%d", &edad);
  if(edad >= 18){
    printf("Eres mayor de edad");
  }else{
    printf("Eres menor de edad");
  }
}
// ------------------------------------------------------------------------------------------------------

// Si queremos comparar dos cadenas debemos llamar a la biblioteca <string.h> y realizar lo siguiente
#include <string.h>
// ....
if(strcmp(sint1, "tos") == 0){ // Compara la variable sint1, con la cadena "tos"
  indicio = 1;
}else{
  indicio = 0;
}
// ....
// Se utiliza la funcion strcmp que devuelve 0 o 1 si las variables son iguales (Verdadero o falso)


// Si queremos asignar cadenas a las variables debemos utilizar otra funcion:
#include <stdio.h>
#include <string.h>
char respuesta [50];
void main (){

  strcpy(respuesta, "Coronavirus"); // Enlaza a la variable la cadena
  print
  f("Usted tiene: %s", respuesta);
}


// ------------------------------------------------------------------------------------------------------

// Estructuras Iterativas
// Recuerda que el valor de inicio de una variables es siempre Cero

i++ // es igual a i = i + 1;
i-- // es igual a i = i - 1;

//Repetir

do {
// Acciones
}while !(condicion de terminacion);

// Ejemplo 
#include <stdio.h>
int i;
void main (){
  printf("Naturales hasta el 10:\n");
  i = 0;
  do{ 
    printf("%d\n", i); // Salida
    i++; // Este es el incremento
  }while (!(i > 10));
}

// Mientras

while (condicion de continuacion){
// Acciones
// Incremento o decremento
}

// Ejemplo
#include <stdio.h>
int i;
void main (){
  i = 0;
  printf("Naturales hasta el 10:\n");
  while (i <= 10){
    printf("%d\n", i);
    i++;
  }
}


// Para

for(Inicializacion; condicion de continuacion; paso){
// Acciones
}

// Ejemplo
#include <stdio.h>
int i;
void main (){
  printf("Naturales hasta el 10:\n");
  for(i = 0; i <= 10; i++){
    printf("%d\n", i);
  }
}

// ------------------------------------------------------------------------------------------------------

// Funciones

<Tipo de valor que devuelve> <Identificador> (<parametros formales>){
  // Lexico local
  // ....
  //Inicio
  // ....
  return (<valor que devuelve>);
}

// Ejemplo
#include <stdio.h>
float radio;
float areaDelCirculo;
// Funcion que devuelve el area de un circulo a partir de su radio
float areaCirc(float r){ 
  // Lexico local
  float l; 
  // Inicio
  l = 3.14 * r * r;
  // <-- l
  return(l);
}
void main (){
  printf("Ingrese el radio del circulo: ");
  scanf("%f", &radio);
  areaDelCirculo = areaCirc(radio);
  printf("El area del circulo es: %f", areaDelCirculo);   
}

// Recuerda que las funciones no pueden modificar el entorno, por ello no debe haber entrada ni salida de nada en las mimas

// ------------------------------------------------------------------------------------------------------

// Acciones

void <nombre> (<parametros formales>){
  // Lexico local
  // ....
  // Inicio
  // ....
}

// Ejemplo
#include <stdio.h>
float nota1, nota2, nota3;
float promedio;
// Recuerda utilizar un puntero (*) para indicar que los parametros son de dato-resultado o de resultado
void CalcularPromedio(float n1, float n2, float n3, float *prom){
  printf("Ingrese la primer nota: ");
  scanf("%f", &n1);
  printf("Ingrese la segunda nota: ");
  scanf("%f", &n2);
  printf("Ingrese la tercer nota: ");
  scanf("%f", &n3);
  *prom = (n1 + n2 + n3) / 3;
  printf("El promedio de tres notas es: %f", *prom);
}

void main (){
  CalcularPromedio(nota1, nota2, nota3, &promedio); 
  // Recuerda utilizar & para indicar que las variables son de tipo resultado o dato-resultado
}

// ------------------------------------------------------------------------------------------------------

// Arreglos
