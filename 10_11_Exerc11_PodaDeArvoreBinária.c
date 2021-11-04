/*Exercício 11. Poda de árvore binária
Crie a função recursiva poda(&A), que remove todas, e só, as folhas de uma árvore binária A.*/

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

void poda(Arv A){
    if (A==NULL){ 
        printf("Folhas nao existem!");
        return;
    }
    else
        poda(A);
}

void exibe (Arv A, int n) {
    if (A==NULL) return;
    exibe(A->dir, n+1);
    printf("%*s%d\n", 3*n, "", A->item);
    exibe(A->esq, n+1);
}

int main (void){
    Arv I = arv(arv(NULL, 2, NULL), 1, arv(NULL, 3, arv(NULL, 4, NULL)));
    exibe(I, 0);
    printf("Podando as folhas da arvore...\n");
    poda(I);
    exibe(I, 0);
    printf("Arvore podada!");
    return 0;
}