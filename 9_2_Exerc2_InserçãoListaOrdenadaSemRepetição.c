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

void ins(Item x, Lista *L) {
	while(*L != NULL && (*L) -> item < x)
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

bool pertence(int r, Lista L) {
	int i = 0;
	while(L != NULL){
		i = L -> item;
		if(r == i){
			return 1;
		}
		L = L -> prox;
	}	
	return 0;
}

void ins_sr(int x, Lista L) {
	if(pertence(x, L) == 1) puts("Numero ja na lista.");
	else ins(x, &L);
}

int main(void) {
	int x, ask=0;
	Lista I = NULL;
	ins (4, &I);
	ins (1, &I);
	ins (3, &I);
	ins (5, &I);
	ins (2, &I);
	exibe(I);
	do {
		printf("\n\nNumero a ser inserido:... ");
		scanf("%d", &x);
		ins_sr(x, I);
		printf("Deseja continuar inserindo?...\n[1] - sim\n[2] - nao\n");
		scanf("%d", &ask);
	}while(ask == 1);
	exibe(I);
	return 0;
}
