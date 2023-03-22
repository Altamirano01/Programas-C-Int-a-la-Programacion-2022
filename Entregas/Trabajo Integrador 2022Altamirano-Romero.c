
/* Trabajo practico integrador final 2022
 Altamirano Facundo - Romero Martin
 22/11/2022
*/

/* Para compilar se utilizo:
-Visual Studio Code con el compilador mingw en Windows
-Codeblocks con el compilador gcc (Windows)
Se hizo las pruebas con el archivo nov2022.dat aportado por la catedra
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

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
TData arreglo, arreglo2;

typedef struct TNodo{
  Tregdiario info;
  struct TNodo *next;
}TNodo;

// tipo auxiliar
typedef char Cadena[250];

Tregdiario registro;
Cadena nombreExterno;
TNodo *lista;
int i, posicion, menu;
long int fecha;
char mensaje[500];
FILE *f;
FILE *g;


// Perfiles de las acciones y funciones

// Accion para agregar un registro al archivo
void AltaRegistro(FILE **f, Cadena nomExt);
// Accion para modificar un registro del arreglo
void ModificarRegistro(FILE **f, int fecha, Cadena nomExt);
// Accion para pasar los datos del archivo a un arreglo
void CargarArreglo(FILE *f, Cadena nomExt, TData *q);
// Funcion recursiva que busca la posicion de un registro
int Buscar(TData q, int i, int fecha);
// Accion que muestra un registro a partir de una posicion
void MuestraReg(TData q, int pos);
// Accion que crea una copia del seguridad del archivo actual
void CopiaDeSeguridad(FILE *f, FILE *g, Cadena nomExt);
// Accion que ordena un arreglo mediante BubbleSort
void OrdenarBurbuja(TData *q);
// Accion que informa los 10 dias en que mas precipitacion hubo
void Precipitaciones(TData q);
//Accion que retorna el archivo con el registro elegido eliminado de manera logica
void Suprimir(FILE **f, Cadena nombreExt);
//Accion que muestra todos los registros activos del archivo
void Mostrar(FILE *f, Cadena nombreExt);
//Accion que muestra el/los dia/s de la maxima temperatura registrada en el archivo
void MaximaTemperatura(FILE *f, Cadena nombreExt);
//Accion que muestra las 10 mayores velocidades de viento registradas en el archivo
void MayorVelocidadViento(FILE *f, Cadena nombreExt);
//Accion que ordena mediante InsertionSort
void OrdenarArreglo (TData *arreglo);
//Recibe el registro e informa si esta vacio o no
bool vacia(TData q);


// Inicio
int main(){
  printf("Ingrese el nombre del archivo a manipular: ");
  scanf("%s", nombreExterno);
  menu = 0;
  do{
    strcpy(mensaje, "\n \tMENU\n");
    printf("%s", mensaje);
    strcpy(mensaje,"1| Alta de registro diario.\n"
                   "2| Suprimir un registro diario.\n"
                   "3| Modificar un registro.\n"
                   "4| Listar.\n"
                   "5| Buscar un registro.\n"
                   "6| Listar dias de maxima temperatura .\n"
                   "7| Listar dias de maxima precipitacion.\n"
                   "8| Listar fechas de mayor a menor velocidad de viento.\n"
                   "9| Realizar copia de seguridad del archivo.\n"
                   "10| Salir.\n");
    printf("%s", mensaje);
		strcpy(mensaje, "SELECCIONE UN NUMERO QUE CORRESPONDA A LA OPERACION QUE DESEE REALIZAR.\n");
		printf("%s", mensaje);
        scanf(" %d", &menu);
    switch  (menu)
    {
      case (1):
        printf("Alta de registro.\n");
        AltaRegistro(&f, nombreExterno);
        menu = 0;
      break;
      case (2):
        printf("Suprimir registro.\n");
        Suprimir(&f, nombreExterno);
        menu = 0;
      break;
      case (3):
        printf("Modificar registro.\n");
        printf("Ingrese una fecha: ");
        scanf("%ld", &fecha);
        ModificarRegistro(&f, fecha, nombreExterno);
        menu = 0;
      break;
      case (4):
        Mostrar(f, nombreExterno);
        menu = 0;
      break;
      case (5):
        printf("Buscar registro.\n");
        printf("Ingrese una fecha: ");
        scanf("%ld", &fecha);
        CargarArreglo(f, nombreExterno, &arreglo);
        i = 0;
        posicion = Buscar(arreglo, i, fecha);
        if(posicion == -1){
          printf("REGISTRO NO ENCONTRADO.\n");
        }else{
          MuestraReg(arreglo, posicion);
        }
        menu = 0;
      break;
      case (6):
        MaximaTemperatura(f, nombreExterno);
        menu = 0;
      break;
      case (7):
        printf("Listar dias de maxima precipitacion.\n");
        CargarArreglo(f, nombreExterno, &arreglo2);
        OrdenarBurbuja(&arreglo2);
        Precipitaciones(arreglo2);
      break;
      case (8):
        MayorVelocidadViento(f, nombreExterno);
        menu = 0;
      break;
      case (9):
        printf("Realizar copia de seguridad.\n");
        CopiaDeSeguridad(f, g, nombreExterno);
        menu = 0;
      break;
      case (10):
        printf("\n");
        printf("Cerrando programa...\n");
        printf("\n");
      break;
      default:
        printf("Cerrando programa...\n");
        return(0);
      break;
    }
  }while(menu != 10);
}


// Acciones y funciones

void AltaRegistro(FILE **f, Cadena nomExt){
  Tregdiario cad, reg;
  int encontrado;
    encontrado = 0;
    *f = fopen(nomExt, "rb");
    //Buscamos si ya existe el archivo correspondiente a la fecha
    printf("Ingrese la fecha en formato [ddmmyyyy]: \n");
    scanf("%ld", &reg.ddmmyyyy);
    printf("Buscando en archivo...\n");
    while(fread(&cad, sizeof(cad), 1, *f) && encontrado != 1){
      if(cad.ddmmyyyy == reg.ddmmyyyy){
        encontrado = 1;
      }
    }
    fclose(*f);
    if(encontrado == 1){
      printf("NO SE PUEDE AGREGAR OTRO REGISTRO CON LA MISMA FECHA.\n");
    }else{
    *f = fopen(nomExt, "ab");
    printf("Ingrese la temperatura maxima: ");
    scanf("%d", &reg.tmax);
    printf("Ingrese la temperatura minima: ");
    scanf("%d", &reg.tmin);
    do{
      printf("Ingrese la Humedad[0 a 100]: ");
      scanf("%d", &reg.HUM);
    }while((reg.HUM < 0) || (reg.HUM > 100));
    do{
      printf("Ingrese la Presion atmosferica[900 a 3600]: ");
      scanf("%d", &reg.PNM);
    }while((reg.PNM < 900) || (reg.PNM > 3600));
    do{
      printf("Ingrese la Direccion del viento[0 a 360]: ");
      scanf("%d", &reg.DV);
    }while((reg.DV < 0) || (reg.DV > 360));
    do{
      printf("Ingrese la Velocidad del viento: ");
      scanf("%d", &reg.FF);
    }while((reg.FF < 0));
    do{
      printf("Ingrese la Precipitacion pluvial acumulada[0 a 1000]: ");
      scanf("%d", &reg.PP);
    }while((reg.PP < 0) || (reg.PP > 1000));
    reg.borrado = 0;
    fwrite(&reg, sizeof(reg), 1, *f);
    printf("REGISTRO AGREGADO.\n");
    fclose(*f);
}

}

void ModificarRegistro(FILE **f, int fecha, Cadena nomExt){
  Tregdiario cad;
  int i;
  int encontrado;
    encontrado = 0;
    *f = fopen(nomExt, "r+b");// Abrimos para lectura y escritura
    fread(&cad, sizeof(Tregdiario), 1, *f);
    while(!feof(*f)){
      if(cad.ddmmyyyy == fecha){
        // Ingresa de nuevo todos los campos del registro excepto la fecha
        printf("Ingrese la temperatura maxima: ");
        scanf("%d", &cad.tmax);
        printf("Ingrese la temperatura minima: ");
        scanf("%d", &cad.tmin);
        do{
          printf("Ingrese la Humedad[0 a 100]: ");
          scanf("%d", &cad.HUM);
        }while((cad.HUM < 0) || (cad.HUM > 100));
        do{
          printf("Ingrese la Presion atmosferica[900 a 3600]: ");
          scanf("%d", &cad.PNM);
        }while((cad.PNM < 900) || (cad.PNM > 3600));
        do{
          printf("Ingrese la Direccion del viento[0 a 360]: ");
          scanf("%d", &cad.DV);
        }while((cad.DV < 0) || (cad.DV > 360));
        do{
          printf("Ingrese la Velocidad del viento: ");
          scanf("%d", &cad.FF);
        }while(cad.FF < 0);
        do{
          printf("Ingrese la Precipitacion pluvial acumulada[0 a 1000]: ");
          scanf("%d", &cad.PP);
        }while((cad.PP < 0) || (cad.PP > 1000));
        cad.borrado = 0;
        i = ftell(*f) - sizeof(Tregdiario);
        fseek(*f, i, SEEK_SET);
        fwrite(&cad, sizeof(Tregdiario), 1, *f);
        printf("REGISTRO MODIFICADO.\n");
        encontrado = 1;// Bandera
        break;
      }
      fread(&cad, sizeof(Tregdiario), 1, *f);
    }
    if(encontrado == 0){
      printf("REGISTRO NO ENCONTRADO.\n");
    }
    fclose(*f);
}


void CargarArreglo(FILE *f, Cadena nomExt, TData *q){
  int i;
  Tregdiario c;
    f = fopen(nomExt, "rb");
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

int Buscar(TData q, int i, int fecha){
  if(i >= q.cant){
    return(-1);
  }else{
    if(q.a[i].ddmmyyyy != fecha){
      i++;
      Buscar(q, i, fecha);
    }else{
      return(i);
    }
  }
}

void MuestraReg(TData q, int pos){
  int i;
    for(i = 0; i < q.cant; i++){
      if(i == pos){
        if(q.a[i].borrado != 1){
          printf("\n");
          printf("Fecha: %ld \n", q.a[i].ddmmyyyy);
          printf("Temperatura maxima: %d \n", q.a[i].tmax);
          printf("Temperatura minima: %d \n", q.a[i].tmin);
          printf("Humedad: %d \n", q.a[i].HUM);
          printf("Presion atmosferica: %d \n", q.a[i].PNM);
          printf("Direccion del viento: %d \n", q.a[i].DV);
          printf("Velocidad del viento: %d \n", q.a[i].FF);
          printf("Precipitacion pluvial total acumulada: %d \n", q.a[i].PP);
          printf("................................................\n");
        }else{
          printf("REGISTRO NO ENCONTRADO.\n");
        }
      }
    }
}

void CopiaDeSeguridad(FILE *f, FILE *g, Cadena nomExt){
  Tregdiario cad;
  Cadena nom;// Nombre del nuevo archivo
    f = fopen(nomExt, "rb");
    if(feof(f)){
      printf("ERROR. ARCHVIO PRINCIPAL VACIO.\n");
    }else{
      printf("Ingrese el nombre del nuevo archivo: ");
      scanf("%s", nom);
      g = fopen(nom, "wb");
      while(fread(&cad, sizeof(cad), 1, f)){
        if(cad.borrado != 1){
          fwrite(&cad, sizeof(cad), 1, g);
          fflush(stdin);
        }
      }
      printf("\nCOPIA DE SEGURIDAD CREADA.\n");
      fclose(g);
    }
    fclose(f);
}

void OrdenarBurbuja(TData *q){
  int i, j;
  Tregdiario aux;
  for(i = 1; i < q->cant; i++){
    for(j = 0; j < q->cant; j++){
      if(q->a[j].PP < q->a[j + 1].PP){
          aux = q->a[j + 1];
          q->a[j + 1] = q->a[j];
          q->a[j] = aux;
      }
    }
  }
}

void Precipitaciones(TData q){
  int i, j;
   i = 0;
   j = 0;
   printf("\nLas 10 mayores precipitaciones son: \n");
   while(j < 10){
    if(q.a[i].borrado == 0){
      j++;
      printf("Fecha: %ld \n", q.a[i].ddmmyyyy);
      printf("Precipitacion: %d\n", q.a[i].PP);
      printf("\n");
    }
    i++;
   }
}

void Mostrar(FILE *archM, Cadena nombreExt){
Tregdiario regM;
  archM = fopen (nombreExt ,"rb");
  while (fread(&regM,sizeof(Tregdiario),1,archM)==1){
    if (regM.borrado == 0){
      printf("Fecha: %ld \n",regM.ddmmyyyy);
      printf("Temperatura maxima: %d \n",regM.tmax);
      printf("Temperatura minima: %d \n",regM.tmin);
      printf("Humedad: %d \n",regM.HUM);
      printf("Presion atmosferica: %d \n",regM.PNM);
      printf("Direccion del viento: %d \n",regM.DV);
      printf("Velocidad del viento: %d \n",regM.FF);
      printf("Precipitacion pluvial total acumulada: %d \n",regM.PP);
      printf("-----------------------------------------------------\n");
    }
  }
  fclose(archM);
}

void Suprimir(FILE **archS, Cadena nombreExt){
  Tregdiario regS;
  long int aBorrar;
  int encontrado;
  FILE *archS1;
  *archS = fopen(nombreExt,"rb");
  archS1 = fopen("temp.dat","wb");
  if ((*archS) == NULL || archS1 == NULL){
    printf("\nERROR AL ABRIR");
  }else{
    printf("Ingrese la fecha del dia a borrar\n");
    scanf("%ld", &aBorrar);
    while(fread(&regS,sizeof(Tregdiario),1,*archS)){
      if(regS.ddmmyyyy == aBorrar){
        encontrado = 1;
        regS.borrado = 1;
        fflush(stdin);
      }
      fwrite(&regS,sizeof(regS),1,archS1);
    }
    fclose(*archS);
    fclose(archS1);
  }
  if(encontrado == 1){
    *archS = fopen(nombreExt,"wb");
    archS1 = fopen("temp.dat","rb");
    if ((*archS) == NULL || archS1 == NULL){
      printf("\nERROR AL ABRIR");
    }else{
      while(fread(&regS,sizeof(Tregdiario),1,archS1)){
        fwrite(&regS,sizeof(regS),1,*archS);
      }
      fclose(*archS);
      fclose(archS1);
      printf("REGISTRO BORRADO.\n");
    }
  }else{
    printf("REGISTRO NO ENCONTRADO.\n");
  }
}

void MaximaTemperatura(FILE *archMaxTemp, Cadena nombreExt){
Tregdiario regMaxTemp;
  TNodo *p, *nuevoN,*aux;
  int tempMax;
  p = NULL;
  tempMax=-999;

  archMaxTemp = fopen(nombreExt,"rb");
  //Busca la maxima temperatura y la guarda en tempMax
  while(fread(&regMaxTemp,sizeof(Tregdiario),1,archMaxTemp)){
    if(regMaxTemp.borrado == 0){
      if (regMaxTemp.tmax >= tempMax){
        tempMax=regMaxTemp.tmax;
      }
    }
  }
  fclose(archMaxTemp);
  archMaxTemp = fopen(nombreExt,"rb");
  //Busca las temperaturas del archivo que sean iguales a tempMax y las copia a la lista
  while(fread(&regMaxTemp,sizeof(Tregdiario),1,archMaxTemp)){
  if ((regMaxTemp.borrado == 0) && regMaxTemp.tmax == tempMax){
      if (p==NULL){
        p = (TNodo *) malloc (sizeof(TNodo));
        p->info.ddmmyyyy = regMaxTemp.ddmmyyyy;
        p->info.tmax = regMaxTemp.tmax;
        p->next = NULL;
        nuevoN = p;
      }else{
        //Obtener (nuevoN)
        nuevoN = (TNodo *) malloc (sizeof(TNodo));
        //(^nuevoN).info.ddmmyyy<- X
        nuevoN->info.ddmmyyyy = regMaxTemp.ddmmyyyy;
        //(^nuevoN).info.tmax<- X
        nuevoN->info.tmax = regMaxTemp.tmax;
        //(^nuevoN).next <- (^p).next
        nuevoN->next = p->next;
        //(^p).next <- nuevoN
        p->next=nuevoN;
      }
    }
  }
  fclose(archMaxTemp);
  aux = p;
  while (aux != NULL){
    printf("Fecha: %ld\n", aux->info.ddmmyyyy);
    printf("Temperatura Maxima: %d C\n", aux->info.tmax);
    printf("==============================================\n");
    aux = aux->next;
  }
}


void MayorVelocidadViento(FILE *archV, Cadena nombreExt){
  TData arr;
  int i;
  archV = fopen(nombreExt,"rb");
  if (archV == NULL){
    printf ("\nERROR AL ABRIR");
  }else{
    fseek(archV,0,SEEK_END);
    // Almacenamos la cantidad de registros cargados en el archivo (de Tregdiario)
    arr.cant = ftell(archV)/sizeof(Tregdiario);
    if (vacia(arr) == false){
      rewind(archV);
      //Cargamos el arreglo
      for(i=0;i<arr.cant;i++){
        fread(&arr.a[i],sizeof(Tregdiario),1,archV);
      }
      OrdenarArreglo(&arr);
      printf("Las mayores 10 velocidades ocurrieron en estos dias: \n \n");
      for (i = 0; i < 10; i++){
        printf("Fecha: %ld \n", arr.a[i].ddmmyyyy);
        printf("Velocidad Maxima: %d \n", arr.a[i].FF);
        printf("======================================================== \n");
      }
    }else{
      printf("Arreglo vacio");
    }
    fclose(archV);
  }
}

void OrdenarArreglo (TData *arreglo){
  int i,j;
  Tregdiario aux;
  //Ordenamos mediante InsertionSort
  for (i = 1; i < arreglo->cant; i++){
    if(arreglo->a[i].borrado == 0){
      aux = arreglo->a[i];
      j = i - 1;
      while (j >= 0 && arreglo->a[j].FF < aux.FF){
        arreglo->a[j + 1] = arreglo->a[j];
        j = j - 1;
      }
      arreglo->a[j + 1] = aux;
    }
  }
}

bool vacia(TData q){
    if(q.cant == 0){
        return true;
    }else{
        return false;
    }
}


