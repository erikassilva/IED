/*Exercício 5. Exibição recursiva decrescente de lista ordenada
Crie a função recursiva exibe_decrescente(L), que exibe em ordem decrescente todos
os itens da lista ordenada L. Depois, faça um programa para testar o funcionamento da função*/

#include <stdio.h>
#include <stdlib.h>

typedef char Itemp;

typedef struct pilha {
   int    max;
   int    topo;
   Itemp *item;
} *Pilha;

Pilha pilha(int m) {
   Pilha P = malloc(sizeof(struct pilha));
   P->max  = m;
   P->topo = -1;
   P->item = malloc(m*sizeof(Itemp));
   return P;
}

int vaziap(Pilha P) {
   if( P->topo == -1 ) return 1;
   else return 0;
}

int cheiap(Pilha P) {
   if( P->topo == P->max-1 ) return 1;
   else return 0;
}

void empilha(Itemp x, Pilha P) {
   if( cheiap(P) ) { puts("pilha cheia!"); abort(); }
   P->topo++;
   P->item[P->topo] = x;
}

Itemp desempilha(Pilha P) {
   if( vaziap(P) ) { puts("pilha vazia!"); abort(); }
   Itemp x = P->item[P->topo];
   P->topo--;
   return x; 
}

Itemp topo(Pilha P) {
   if( vaziap(P) ) { puts("pilha vazia!"); abort(); }
   return P->item[P->topo];
}

void destroip(Pilha *Q) {
   free((*Q)->item);
   free(*Q);
   *Q = NULL;
}

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

void exibe_decrescente (Lista L){
    Pilha P = pilha(5);
    int n = 0;
    if (L == NULL) return;
    n = L->item;
    empilha (n, P);
    L = L->prox;
    exibe_decrescente(L);
    printf("%d, ", desempilha(P));
}

int main (void){
    Lista I = NULL;
    ins (4, &I);
    ins (1, &I);
    ins (3, &I);
    ins (5, &I);
    ins (2, &I);
    exibe_decrescente(I);
    return 0;
}
