/*
 * Programma per la dimostrazione della precisione dell'integrazione numerica
 * al variare di n, date funzioni pre-integrate
*/

#include <stdio.h>
#include <math.h>

//Funzione di selezione della funzione matematica

double selectionFunction(int sel, float xvalue){
	switch(sel){
		case 1:
			printf("ok3");
			return xvalue*xvalue;
		break;
		
		default:
			printf("Errore! selezione della funzione invalida.");
		break;
	}
}

//Main

void main(){
	//Dichiarazioni variabili
	int rettversion, selfuntion, selmethod;
	double a, b, h, n, area;
	//Input
	printf("Scegli la funzione:\n 1 - f(x)=x^2\n");
	printf("La tua selezione: ");
	scanf("%d", &selfuntion);
	printf("Ora inserisci il metodo di integrazione numerica:\n 1 - Metodo dei rettangoli\n");
	printf("La tua selezione: ");
	scanf("%d", &selmethod);
	if(selmethod == 1){
		printf("Dato che hai scelto il metodo dei rettangoli indica quale variante desideri:\n 1 - Partenza dal primo valore\n 2 - Partenza dal secondo valore\n");
		printf("La tua selezione: ");
		scanf("%d", &rettversion);
	}
	printf("Ora definisci il limite inferiore dell'integrale:\n");
	printf("a =  ");
	scanf("%f", &a);
	printf("Ora definisci il limite superiore dell'integrale:\n");
	printf("b =  ");
	scanf("%f", &b);
	printf("Ora definisci il numero dei passi:\n");
	printf("n =  ");
	scanf("%f", &n);
	//Calcolo
	h = (b - a)/n; //h = lunghezza del passo
	switch(selmethod){
		case 1: //Metodo dei rettangoli
			printf("ok1");
			switch(rettversion){
				case 1: //Metodo dei rettangoli variante iniziando dal primo valore
					printf("ok2");
					for(int i=0; i <= (n-1); i++){
						printf("ok3");
						area += h*selectionFunction(selfuntion, i*h+a);
						printf("step area =%f", area);
					}
				break;
				
				case 2://Metodo dei rettangoli variante iniziando dal secondo valore
					for(int i=1; i <= n; i++){
						area += h*selectionFunction(selfuntion, i*h+a);
					}
				break;
				
				default:
					printf("Errore! selezione della variante del metodo dei rettangoli invalida.");
				break;
			}
		break;
		
		case 2: //Metodo dei trapezi
			
		break;
		
		case 3: //Metodo delle parabole
			
		break;
		
		default:
			printf("Errore selezione del metodo invalida.");
		break;
	}
	printf("area = %f\n", area);
}
