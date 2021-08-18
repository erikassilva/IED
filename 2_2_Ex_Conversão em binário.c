//Exemplo 2. Conversão em binário

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h" 

int main (void){

	int n;
	Pilha P = pilha(32); //32 = armazena 32 posições na pilha que vai do 0 até 31
	printf("Decimal? ");
	scanf("%d", &n);
	do{
		empilha(n%2, P);
		n/= 2;
	}while ( n!= 0);
	printf("Binario: ");
	while (!vaziap(P))
		printf("%d", desempilha(P));
	printf("\n");
	destroip(&P);
	return 0;
}
