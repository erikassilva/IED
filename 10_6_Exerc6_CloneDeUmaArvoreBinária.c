/*Exercício 6. Clone de uma árvore binária
Crie a função recursiva clone(A), que devolve um clone (cópia) da árvore binária A. Em
seguida, faça um programa para testar o funcionamento da função.*/

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct arv {
    struct arv *esq;
    Item item;
    struct arv *dir;
} *Arv;

Arv arv (Arv e, Item x, Arv d) {
    Arv n = malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

Arv clone (Arv A) {
    if ( A == NULL ) return NULL;
    return arv(clone(A->esq),A->item,clone(A->dir));
}

void exibe (Arv A, int n) {
    if (A==NULL) return;
    exibe(A->dir, n+1);
    printf("%*s%d\n", 3*n, "", A->item);
    exibe(A->esq, n+1);
}

int main(void) {
	Arv I = arv(arv(arv(NULL, 4, NULL), 2, arv(NULL, 5, NULL)), 1, arv(arv(arv(NULL, 8, NULL), 6, arv(NULL, 9, NULL)), 3, arv(NULL, 7, NULL)));
	printf("Arv I\n");
    exibe(I, 0);
    printf("Arv H\n");
    Arv H = clone (I);
    exibe(H, 0);
	return 0;
}
