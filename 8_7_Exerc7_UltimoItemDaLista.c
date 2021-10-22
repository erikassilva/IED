/*Exercício 7. Último item da lista
Crie a função ultimo(L), que devolve o último item da lista L (note que, se a lista estiver
vazia, deve ocorrer um erro fatal). Em seguida, faça um programa para testar essa função*/

#include <stdio.h>
#include <stdlib.h>

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
}

void ultimo( L ){
    

}

int main(void){
    Lista H = no(4, no(2, NULL));
    Lista I = no(3, no(1, no(5, NULL)));
    printf("H = "); exibe(H);
    printf("I = "); exibe(I);
    printf("Pressione enter"); getchar();
    anexa(&H, I);
    printf("H = "); exibe(H);
    printf("I = "); exibe(I);
    destroi(&H);
    destroi(&I);
    printf("H = "); exibe(H);
    printf("I = "); exibe(I);
    return 0;
}