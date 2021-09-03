/*Exercicio 3 - Compartilhamento de CPU
Esse programa simula o compartilhamento de uma CPU entre vários processos. Qual a saída?*/

#include <stdio.h>
#define tempo 3

// fila.h - implementacao dinamica sequencial de fila

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
	
	Fila F = fila(5);
	enfileira(17, F);
	enfileira(25, F);
	enfileira(39, F);
	enfileira(46, F);
	
	while (!vaziaf(F)){
		int x = desenfileira(F);
		int p = x/10;
		int t = x%10;
		if ( t>3 ) enfileira (p*10+(t-tempo), F);
		else printf("Processo %d concluido\n", p);
	}
	destroif(&F);
	
	return 0;
}