/*Exercício 5. Altura de uma árvore binária
Crie a função recursiva altura(A), que devolve a altura de uma árvore binária A, supondo
que árvore vazia tem altura 0. Depois, faça um programa para testar o funcionamento da função.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int altura(Arv A){
    if (A==NULL) return -1;
    else{
        int aEsq = altura(A->esq);
        int aDir = altura(A->dir);
        if ( aEsq < aDir) return aDir + 1;
        else return aEsq + 1;
    }
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
    printf("Folhas da arvore binaria: %d", altura(I));

    return 0;
}
