/*Exercício 1. Teste do programa
Digite e teste o programa do Exemplo 4, com as seguintes expressões infixas (coloque todos os parênteses necessários para que o programa funcione corretamente)
2 * 3 + 8 / 4
9 – 5 – 1
2 + 3 * 4 - 5
(3 + 4) * (8 - 6) / 2*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char o){
	switch( o ){
		case '(': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
	}
	return -1;
}

char *posFixa(char *e){
	static char s[256];
	int i=0, j = 0;
	Pilha P = pilha(256);
	
	for (i=0; e[i]; i++) 
		if (e[i] == '(') empilha('(', P);
		else if( isdigit(e[i]) ) s[j++] = e[i];
		else if (strchr("+*-/", e[i])) {
			while ( !vaziap(P) && prio(topo(P) ) >= prio(e[i]) ) s[j++] = desempilha(P);
			empilha(e[i], P);
		}
		else if ( e[i] == ')' ){
			while ( topo(P) != '(' ) s[j++] = desempilha(P);
			desempilha(P);
		}
	while( !vaziap(P)) s[j++] = desempilha(P);
	s[j] = '\0';
	destroip(&P);
	return s;
}

int main (void){
	
	char e[256];
	printf("Infixa? ");
	gets(e);	
	printf("Posfixa: %s\n", posFixa(e));
	return 0;
}