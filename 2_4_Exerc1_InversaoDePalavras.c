/*Exercício 1. Inversão de palavras
Usando uma pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase
dada pelo usuário. Por exemplo, se for digitada a frase "apenas um teste", o programa
deverá exibir a frase "sanepa mu etset".*/

#include <stdio.h>
#include "pilha.h"

int main (void){

	char fraseUsuario[50];
	int posicaoVetorFrase = 0, numPalavras = 1;
	Pilha A = pilha(50);
	printf("Digite uma frase: ");
	gets(fraseUsuario);
	
	printf("Frase Inversa: ");
	
	int i = 0;
	for (i=0; fraseUsuario[i]; i++)
		if (fraseUsuario[i] == ' ' )
			numPalavras++;
			
	while(numPalavras != 0){
		for(posicaoVetorFrase; (fraseUsuario[posicaoVetorFrase]!=' '); posicaoVetorFrase ++ ){
			if (fraseUsuario[posicaoVetorFrase] == '\0') 
				break;
			empilha(fraseUsuario[posicaoVetorFrase], A);
		}
		posicaoVetorFrase++;
		
		while ( !vaziap(A)) 
			printf("%c", desempilha(A));
		printf(" ");
		numPalavras--;
	}
	getch();
	printf("\n");
	destroip(&A);
	
	return 0;
}
