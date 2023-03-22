#include<stdio.c>
float ganancias;
float perdidas; 
float balance = 0;
float gananciaNeta = 0;
float perdidaNeta = 0;
char finalizar

void main(){
	while (finalizar != 'S'){
		printf("Ingrese las ganancias en forma de listado\n");
		scanf("%f", &ganancias);
		printf("Desea finalizar S/N' \n");
		scanf("%s", &finalizar);
		gananciaNeta = gananciaNeta + ganancias;
	}
	
	while (finalizar != 's'){
		printf("Ingrese las perdidas en numeros negativos y en forma de listado\n");
		scanf("%f", &perdidas);
		printf("Desea finalizar s/n' \n");
		scanf("%s", &finalizar);

	    perdidaNeta = perdidaNeta + perdidas;
	}
	
	balance = gananciaNeta + perdidaNeta;
	
	if(balance > 0){
		printf("El balance ha sido positivo\n");
	}else if(balance < 0){
		printf("El balance ha sido negativo\n")
	}else if(balance == 0)
		printf("El balance ha sido nulo\n")
	}
	
	printf("%f \n", balance);
}