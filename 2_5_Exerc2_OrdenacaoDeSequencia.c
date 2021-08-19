/*Exercício 2. Ordenação de sequência
Crie um programa que usa duas pilhas A e B para ordenar uma sequência de n números reais
dados pelo usuário. A ideia é organizar a pilha A de modo que nenhum item seja empilhado sobre
outro menor (use a pilha B apenas como espaço de manobra), depois, descarregue e exiba os
itens da pilha A*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main (void){

	float n[5];
	Pilha A = pilha(5);
	Pilha B = pilha(5);
	float aux = 0;
	int i=0;

	for ( i=0; i<5; i++){
		printf("Informe um numero: ");
		scanf("%f", &n[i]);
		empilha(n[i], A);
	}		
	while (!vaziap(A)){
		aux = desempilha(A);
		while(!vaziap(B) && topo(B) > aux){empilha(desempilha(B),A);}	
		empilha(aux, B);	
	}
	while(!vaziap (B)){empilha(desempilha(B), A);}
	while(!vaziap(A)){printf("%.2f\n", desempilha(A));}
	destroip(&A);
	destroip(&B);
	
	return 0;
}
