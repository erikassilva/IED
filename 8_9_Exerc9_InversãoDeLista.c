/* Exercício 9. Inversão de lista
Crie a função inversa(L), que cria e devolve uma lista contendo os mesmos itens de L, mas
na ordem inversa. Por exemplo, se L for a lista [1,2,3], a chamada inversa(L) deve
devolver a lista [3,2,1]. Em seguida, faça um programa para testar essa função.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Itemp;

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

Lista no(Item x, Lista p){
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
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

void inversa(Lista L){
    Pilha P = pilha(10);
    while(L != NULL){
        empilha(L->item, P);
        L = L->prox;
    }
    printf("[");
    while(! vaziap(P))
        printf("%d, ", desempilha(P));
    printf("\b\b]");
	printf("\n");
	destroip(&P);
}

int main(void){
    int x;
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    inversa(I);
    return 0;
}