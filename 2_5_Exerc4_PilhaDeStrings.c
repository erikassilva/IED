/*Exercício 4. Pilha de strings
Qual será a saída, se o usuário digite as cadeias "um", "dois" e "tres"? Por quê?*/

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void){

	Pilha P = pilha(5);
	char s[11];
	int i;

	for(i=1; i<=3; i++){
		printf("? ");
		gets(s);
		empilha(s,P);
	}
		
	while( !vaziap(P) ) puts (desempilha(P));

	return 0;
}

/*Nesse código o laço for registra a entrada digitada no teclado e a cada chamada do empilha
ele sobrescreve o registro anterior na pilha, considerando somente a última string chamada.*/

