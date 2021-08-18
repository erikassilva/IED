//Exemplo 3. Inversão de cadeia

#include <stdio.h>
#include "pilha.h"

int main (void){

	char c[81];
	int i;
	Pilha P = pilha(81);
	printf("Cadeia? ");
	gets(c);
	for ( i=0; c[i]; i++)
		empilha(c[i], P);
	printf("Inverso: ");
	while ( !vaziap(P))
		printf("%c", desempilha(P));
	printf("\n");
	destroip(&P);

	return 0;
}
