//Compilador Pelles C

#include <stdio.h> //biblioteca de entrada STandarD Input/Output Header
  
int main (void) { 
	//main é a função principal - formato pode variar conforme o compilador
	//void - sem retorno
	
	int n;
	printf("Numero? ");
	scanf("%d", &n); // ("formatação", &variavel1, "variavel2)
	printf("Dobro = %d\a\n", 2*n); //("formatação", &valor1, "valor2)
	
	return 0; //saída da função retorno 0 por causa do int - formato pode variar conforme o compilador
}

//ctrl+F5 para compilar e executar
//tipos de dados char - caracter, int - numeros inteiros, float e double numeros reais, void - ausência de valor
//não existe o tipo string mas existem constantes desse tipo "b", "1", "Ana"
//lógicos - !, &&, ||
//Endereço - &
//Lógica - falso = 0 e verdadeiro = 1, todo valor diferente de 0 é considerado verdadeiro
//Divisão ex. 7/2 == 3 e 7/2.0 == 3.5
//caracteres especiais - controle: \a, \b, \n, \r, \t, \0 (char acaba com \0), \', \", \\
//caracteres especiais - formato: %c, %d, %o (octal), %x (hexadecimal), %X (hexadecimal), %f, %1f, %%