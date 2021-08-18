//Exercicio 13. Uma lista de números
//Alocação dinâmica encadeadausada para armazenar uma coleção de itens em posições arbitrárias de memória
//Alocação dinâmica encadeada é feita com registros dinâmicos, criados com malloc()
//Na alocação dinâmica encadeada o acesso aos itens é lento, mas inserção e remoção são rápidas!

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int item;
	struct no *prox;
} *Lst;
Lst no(int x, Lst p){
	Lst n = malloc(sizeof(struct no));
	n-> item = x;
	n-> prox = p;
	return n;
}

int main (void){

		Lst p = no(1, no(2, no(3, NULL)));
		while( p!= NULL ){
			printf("%d\n", p->item);
			p = p->prox;
		}

		return 0;
}