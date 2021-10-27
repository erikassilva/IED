/*Exercício 8. Pertinência em lista
Crie a função pertence(x,L), que verifica se o item x está armazenado na lista L. Em
seguida, faça um programa para testar essa função*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void pertence(int x, Lista L){
    int count = 0;
    while (L != NULL){
        int c = L->item;
        if ( x == c ) count++;
        L = L->prox;
    }
    if (count >=1)
        printf("O numero %d pertence a lista!", x);
    else printf("O numero %d nao pertence a lista!", x);
}

int main(void){
    int x;
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    printf("\nDigite um numero: ");
    scanf("%d", &x);
    pertence(x, I);
    return 0;
}