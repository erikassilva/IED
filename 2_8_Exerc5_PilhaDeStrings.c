/*Exercício 5. Pilha de strings
Use _strdup(s), declarada em string.h, para corrigir o programa do exercício anterior.
Essa função duplica a cadeia s num área de memória, alocada pela função malloc(), e devolve
o endereço dessa área. Depois de usada, essa cópia pode ser destruída com a função free()*/

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void){

	Pilha P = pilha(10);
	char s[11];
	int i;

	for(i=1; i<=3; i++){
		printf("? ");
		gets(s);
		empilha(_strdup(s),P);
	}
		
	while( !vaziap(P) ) puts (desempilha(P));
	free(_strdup(s));
	printf("\n");

	return 0;
}