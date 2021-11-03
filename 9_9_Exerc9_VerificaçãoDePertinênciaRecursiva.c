/*Exercício 9. Verificação de pertinência recursiva
Crie a função recursiva pert_rec(x,L), que verifica se o item x está na lista ordenada L.
Em seguida, faça um programa para testar o funcionamento da função*/

#include <stdio.h>
#include <stdlib.h>

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

void ins (Item x, Lista *L){
    while( *L != NULL && (*L)->item < x)
        L = &(*L)->prox;
    *L = no(x, *L);
}

void exibe (Lista L){
    printf("[");
    while(L != NULL){
        printf("%d, ", L->item);
        L = L->prox;
    }
    printf("\b\b]");
    printf("\n");
}

int pert_rec(Item x, Lista L){
    if ( L != NULL && L->item < x ){
        L = L->prox;
        return pert_rec(x, L);
    }
    return ( L!= NULL && L->item == x );
}

int main (void) {
    Lista I = NULL;
    ins(4, &I); ins(1, &I); ins(3, &I); ins(2, &I);
    printf("%d\n", pert_rec(5, I));
    printf("%d\n", pert_rec(3, I));
    printf("%d\n", pert_rec(2, I));
    printf("%d\n", pert_rec(7, I));
    return 0;
}