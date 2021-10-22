/*Exercício 4. Soma dos itens da lista
Adicione no programa do exercício anterior (8_3) uma função para calcular a soma dos itens da lista.
Por exemplo, considerando que I aponta a lista de inteiros [3,1,5], a chamada soma(I)
deve devolver a resposta 9*/

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

int tamanho(Lista L){
    int t = 0;
    while (L){
        t++;
        L = L->prox;
    }
    return t;
}

int soma(Lista L){
    int s = 0;
    while (L){
        s += L->item;
        L = L->prox;
    }
    return s;
}

int main(void){
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    printf("\nTamanho = %d\n", tamanho(I));
    printf("\nSoma da lista = %d\n", soma(I));
    return 0;
}