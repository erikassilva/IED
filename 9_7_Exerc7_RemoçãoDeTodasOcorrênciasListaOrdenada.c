/*Exercício 7. Remoção de todas as ocorrências em lista ordenada
Crie a função iterativa rem_todo(x,&L), que remove toda ocorrência do item x na lista
ordenada L. Em seguida, faça um programa para testar o funcionamento da função.*/

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
	Lista n = malloc(sizeof(struct no));
	n -> item = x;
	n -> prox = p;
	return;
}

void ins (Item x, Lista *L){
    while( *L != NULL && (*L)->item < x)
        L = &(*L)->prox;
    *L = no(x, *L);
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

void rem_todo ( Item x, Lista *L ){
    while ( *L != NULL && (*L)->item < x )
        L = &(*L)->prox;
    if ( *L == NULL || (*L)->item > x ) return;
    while(*L != NULL && (*L) -> item == x) {
		Lista n = *L;
		*L = n -> prox;
		free(n);
    }
}

int main (void){
    Lista I = NULL;
    ins(4, &I); 
    ins(2, &I);
    ins(1, &I); 
    ins(3, &I); 
    ins(5, &I); 
    ins(2, &I); 
    ins(4, &I);
    ins(4, &I);
    exibe(I);
    rem_todo(3, &I);
    exibe(I);
	rem_todo(2, &I);
	exibe(I); 
	rem_todo(4, &I);
	exibe(I);
	
    return 0;
}