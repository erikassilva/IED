/*Exercício 6. Programa para destruição de lista
Altere o programa criado no Exercício 5 (8_5) de modo que, antes de executar o comando return
0, a função destrua as listas H e I e exiba seus valores*/

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

void anexa(Lista *A, Lista B){
    if ( !B ) return;
    while( *A ){
        A = &(*A)->prox;
    }
    *A = B;
}

void destroi(Lista *L){
    while ( *L ){
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
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
