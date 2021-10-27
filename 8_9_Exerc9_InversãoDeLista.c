/* Exercício 9. Inversão de lista
Crie a função inversa(L), que cria e devolve uma lista contendo os mesmos itens de L, mas
na ordem inversa. Por exemplo, se L for a lista [1,2,3], a chamada inversa(L) deve
devolver a lista [3,2,1]. Em seguida, faça um programa para testar essa função.*/

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

int tamanho(Lista L){
    int t = 0;
    while (L){
        t++;
        L = L->prox;
    }
    return t;
}

int inversa(Lista L){
    

    
}

int main(void){
    int x;
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    printf("%d", inversa(I));
    return 0;
}