/*Exercício 7. Pertinência em árvore binária
Crie a função recursiva pertence(x,A), que determina se o item x pertence à árvore
binária A. Em seguida, faça um programa para testar o funcionamento da função*/

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

int pertence (Item x, Arv A){
    if ( A != NULL ){
        A = A->esq;
        return pertence(x, A->esq);
    }
    else    
        A = A->dir;
        return pertence(x, A->dir);
}

void exibe (Arv A, int n) {
    if (A==NULL) return;
    exibe(A->dir, n+1);
    printf("%*s%d\n", 3*n, "", A->item);
    exibe(A->esq, n+1);
}

int main (void){
    Arv I = arv(arv(arv(NULL, 4, NULL), 2, arv(NULL, 5, NULL)), 1, arv(arv(arv(NULL, 8, NULL), 6, arv(NULL, 9, NULL)), 3, arv(NULL, 7, NULL)));    
    exibe(I, 0);
    printf("Pertinencia da Arvore: %d%d", pertence(5, I));

    return 0;
}
