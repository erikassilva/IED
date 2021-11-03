/*Exercício 2. Inserção em lista ordenada sem repetição
Crie a função iterativa ins_sr(x,&L), que insere o item x na lista ordenada L somente se x
não estiver em L. Em seguida, faça um programa para testar o funcionamento da função.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
	Lista n = malloc(sizeof(struct no));
	n -> item = x;
	n -> prox = p;
	return;
}

void ins_sr(Item x, Lista *L) {
	while(*L != NULL && (*L) -> item < x)
		if ((*L)->item != x)
			L = &(*L) -> prox;
	*L = no(x,*L);
}

void exibe(Lista L) {
	printf("[");
	while(L != NULL) {
		printf("%d, ", L -> item);
		L = L -> prox;
	}
	printf("\b\b]");
}

int main(void) {
	int x, ask=0;
	Lista I = NULL;
	ins_sr(4, &I);
	ins_sr(1, &I);
	ins_sr(3, &I);
	ins_sr(5, &I);
	ins_sr(3, &I);
	exibe(I);
	
	return 0;
}
