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
			return xvalue*xvalue;
		break;
		
		default:
			printf("exit Error");
		break;
	}
}

//Main

void main(){
	//Dichiarazioni variabili
	int rettversion, selfunction, selmethod, i;
	double a, b, h, area, n;
	//Input
	while(1){
		printf("Scegli la funzione:\n 1 - f(x)=x^2\n");
		printf("La tua selezione: ");
		scanf("%d", &selfunction);
		if((selfunction >= 1)&&(selfunction <= 1))
			break;
		else
			printf("***Input non valido***\n\n");
	}
	while(1){
		printf("Ora inserisci il metodo di integrazione numerica:\n 1 - Metodo dei rettangoli\n 2 - Metodo dei trapezi\n 3 - Metodo delle parabole\n");
		printf("La tua selezione: ");
		scanf("%d", &selmethod);
		if((selmethod >= 1)&&(selmethod <= 3))
			break;
		else
			printf("***Input non valido***\n\n");
	}
	if(selmethod == 1){
		while(1){
			printf("Dato che hai scelto il metodo dei rettangoli indica quale variante desideri:\n 1 - Partenza dal primo valore\n 2 - Partenza dal secondo valore\n");
			printf("La tua selezione: ");
			scanf("%d", &rettversion);
			if((rettversion >= 1)&&(rettversion <= 2))
				break;
			else
				printf("***Input non valido***\n\n");
		}
	}
	printf("Ora definisci il limite inferiore dell'integrale:\n");
	printf("a =  ");
	scanf("%lf", &a);
	printf("Ora definisci il limite superiore dell'integrale:\n");
	printf("b =  ");
	scanf("%lf", &b);
	printf("Ora definisci il numero dei passi:\n");
	printf("n =  ");
	scanf("%lf", &n);
	//Calcolo
	h = (b - a)/n; //h = lunghezza del passo
	switch(selmethod){
		case 1: //Metodo dei rettangoli
			switch(rettversion){
				case 1: //Metodo dei rettangoli variante iniziando dal primo valore
					for(i=0; i <= (n-1); i++){
						area += h*selectionFunction(selfunction, i*h+a);
					}
				break;
				
				case 2://Metodo dei rettangoli variante iniziando dal secondo valore
					for(i=1; i <= n; i++){
						area += h*selectionFunction(selfunction, i*h+a);
					}
				break;
				
				default:
					printf("exit Error");
				break;
			}
		break;
		
		case 2: //Metodo dei trapezi
			for(i=0; i <= (n-1); i++){
				area += h*selectionFunction(selfunction, i*h+a);
			}
			for(i=1; i <= n; i++){
				area += h*selectionFunction(selfunction, i*h+a);
			}
			area /= 2;
		break;
		
		case 3: //Metodo delle parabole
			for(i=0; i <= n; i++){
				if((i==0)&&(i==n))
					area += selectionFunction(selfunction, i*h+a);
				if((i % 2) == 0)
					area += 2*selectionFunction(selfunction, i*h+a);
				if((i % 2) == 1)
					area += 4*selectionFunction(selfunction, i*h+a);
			}
			area *= h/3;
		break;
		
		default:
			printf("exit Error");
		break;
	}
	printf("Area = %lf\n", area);
}
