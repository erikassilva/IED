//Exemplo 4. Programa de conversão de infixa parentesiada

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *posFixa(char *e){
	static char s[256];
	int i=0, j = 0;
	Pilha P = pilha(256);
	
	for (i=0; e[i]; i++) 
		if( isdigit(e[i]) ) s[j++] = e[i];
		else if (strchr("+*-/", e[i])) empilha(e[i], P);
		else if ( e[i] == ')' ) s[j++] = desempilha(P);
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
