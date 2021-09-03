/*Exercicio 2 - Saída de Programa
Qual a saída exibida pelo programa a seguir?*/

#include <stdio.h>
#include <stdlib.h>

#define avanca(i) (i = (i+1) % F->max)

typedef int Itemf;

typedef struct fila {
   int   max;
   int   total;
   int   inicio;
   int   final;
   Itemf *item;
} *Fila;

Fila fila(int m) {
   Fila F = malloc(sizeof(struct fila));
   F->max    = m;
   F->total  = 0;
   F->inicio = 0;
   F->final  = 0; 
   F->item   = malloc(m*sizeof(Itemf));
   return F;
}

int vaziaf(Fila F) {
   return ( F->total == 0 );
}

int cheiaf(Fila F) {
   return ( F->total == F->max );
}

void enfileira(Itemf x, Fila F) {
   if( cheiaf(F) ) { puts("fila cheia!"); abort(); }
   F->item[F->final] = x;
   avanca(F->final);
   F->total++;
}

Itemf desenfileira(Fila F) {
   if( vaziaf(F) ) { puts("fila vazia!"); abort(); }
   Itemf x = F->item[F->inicio];
   avanca(F->inicio);
   F->total--;
   return x;
}

void destroif(Fila *G) {
   free((*G)->item);
   free(*G);
   *G = NULL;
}

int main(int argc, char *argv[]) {
	
	int i=0;
	Fila F = fila(5);
	for(i=0; i<=3; i++)
		enfileira('A'+i, F);
	while( !vaziaf(F))
		printf("%c\n", desenfileira(F));
	destroif(&F);
	
	return 0;
}