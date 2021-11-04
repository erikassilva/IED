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
    if ( A == NULL ) return;
    Arv n = malloc(sizeof(arv));
    n->esq = clone(A->esq);
    n->dir = clone(A->dir);
    n->item = A->item;
    return n;
}

void exibe (Arv A, int n) {
    if (A==NULL) return;
    exibe(A->dir, n+1);
    printf("%*s%d\n", 3*n, "", A->item);
    exibe(A->esq, n+1);
}

int main (void){
    Arv I = arv(arv(NULL, 
                    2, 
                    NULL), 
                1, 
                arv(NULL, 
                    3, 
                    arv(NULL,   
                        4, 
                        NULL)));
    //exibe(I, 0);
    clone (I);

    return 0;
}