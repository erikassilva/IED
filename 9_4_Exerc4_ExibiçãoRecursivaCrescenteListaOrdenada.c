/*Exercício 4. Exibição recursiva crescente de lista ordenada
Crie a função recursiva exibe_crescente(L), que exibe em ordem crescente todos os
itens da lista ordenada L. Depois, faça um programa para testar o funcionamento da função.*/

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no (Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void ins (Item x, Lista *L){
    while( *L != NULL && (*L)->item < x)
        L = &(*L)->prox;
    *L = no(x, *L);
}

void exibe_crescente (Lista L){
    if (L == NULL) return;
    printf("%d, ", L->item);
    L = L->prox;
    exibe_crescente(L);
    printf("\b\b");
}

int main (void){
    Lista I = NULL;
    ins (4, &I);
    ins (1, &I);
    ins (3, &I);
    ins (5, &I);
    ins (2, &I);
    exibe_crescente(I);
    return 0;
}
