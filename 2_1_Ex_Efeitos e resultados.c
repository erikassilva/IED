//Exemplo 1. Efeitos e resultados

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main (void){
	
	int n;

	Pilha P = pilha(3); 
	vaziap(P);
	empilha(1,P);
	empilha(2,P);
	empilha(3,P);
	cheiap(P);
	while (!vaziap(P))
		printf("%d\n", desempilha(P));
	destroip(&P);
	return 0;
}