/*Exercicio 1 - Cadeia Palíndroma
O programa do Exemplo 2 não reconhece "Amor a Roma" como uma cadeia palíndroma.
Use a função toupper(), declarada em ctype.h, para resolver esse problema (essa
função converte uma letra minúscula em maiúscula).*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"
#define avanca(i) (i = (i+1) % F->max)

typedef char Itemf;

typedef struct fila{
	int max;
	int total;
	int inicio;
	int final;
	Itemf *item;
} *Fila;

Fila fila(int m) {
	Fila F = malloc(sizeof(struct fila));
	F->max = m;
	F->total = 0;
	F->inicio = 0;
	F->final = 0;
	F->item = malloc(m*sizeof(Itemf));
	return F;
}

int vaziaf(Fila F){
	return (F->total == 0);
}

int cheiaf(Fila F){
	return (F->total == F->max);
}
	
void enfileira(Itemf x, Fila F){
	if (cheiaf(F)){
		puts ("Fila cheia!");
		abort();
	}
	F->item[F->final] = x;
	avanca(F->final);
	F-> total++;
}
	
Itemf desenfileira(Fila F){
	if( vaziaf(F)){
		puts("Fila vazia!");
		abort();
	}
	Itemf x = F->item[F->inicio];
	avanca(F->inicio);
	F->total--;
	return x;
}

void destroif(Fila *F){
	free((*F)-> item);
	free(*F);
	*F = NULL;
}

int main(int argc, char *argv[]) {
	
	int i=0;
	char s[256];
	Fila F = fila(256);
	Pilha P = pilha(256);
	printf("\nFrase? ");
	gets(s);
	for (i=0; s[i]; i++)
		s[i] = toupper(s[i]);
		if( isalpha (s[i])){
			enfileira(s[i], F);
			empilha(s[i], P);
		}
	while ( !vaziaf(F) && desenfileira(F) == desempilha(P) );
	if (vaziaf(F)) puts ("A frase e palindroma");
	else puts ("A frase nao e palindroma");
	destroif(&F);
	destroip(&P);
	
	return 0;
}