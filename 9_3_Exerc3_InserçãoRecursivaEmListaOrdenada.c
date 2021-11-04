/*Exercício 3. Inserção recursiva em lista ordenada
Crie a função recursiva ins_rec(x,&L), que insere um item x numa lista ordenada L. Em
seguida, faça um programa para testar o funcionamento da função*/

#include <stdio.h>
#include <stdlib.h>

#define fmt "%d "
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

void ins_rec(Item x, Lista *L) {
     if (*L != NULL && (*L)->item < x){
        ins_rec(x, &(*L)->prox);
     }else{
        *L = no(x,*L);
     }
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

int main (void){
    system("cls");
    printf("\nInserir em lista ordenada\n");
    Lista I = NULL;
    ins_rec (4, &I);
    ins_rec (1, &I);
    ins_rec (3, &I);
    ins_rec (5, &I);
    ins_rec (2, &I);
    exibe(I);
    return 0;
}