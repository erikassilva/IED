/*Exercício 2. Outra forma de exibição
Altere a função exibe() do 8_1, de modo que os itens da lista sejam exibidos entre colchetes e
separados por vírgulas. A lista vazia deve ser exibida como [].
Por exemplo, após a alteração da função exibe(), a execução do código abaixo deve produzir
a saída indicada a seguir: [3,1,5]*/

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

int main(void){
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    return 0;
}
