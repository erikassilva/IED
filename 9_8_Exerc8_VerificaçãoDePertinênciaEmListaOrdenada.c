/*Exercício 8. Programa para verificação de pertinência em lista ordenada
Complete e execute o programa a seguir.
#include <stdio.h>
#include <stdlib.h>
...
int main(void) {
Lista I = NULL;
ins(4,&I); ins(1,&I); ins(3,&I); ins(2,&I);
printf("%d\n",pert(5,I));
printf("%d\n",pert(3,I));
return 0;
}*/

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

int pert(Item x, Lista L){
    while( L != NULL && L->item < x )
        L = L->prox;
    return ( L!= NULL && L->item == x );
}

int main (void) {
    Lista I = NULL;
    ins(4, &I); ins(1, &I); ins(3, &I); ins(2, &I);
    printf("%d\n", pert(5, I));
    printf("%d\n", pert(3, I));
    return 0;
}