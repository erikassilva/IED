/*Exercício 8. Função hanói
Crie a função recursiva hanói(n,origem,auxiliar,destino), queresolve o problema dasTorres de
Hanói, movendo n discos da torre origem, para a torre destino, usando a torre auxiliar. Por
exemplo, a chamada hanói(3, 'A', 'B', 'C') deve resolver o problema discutido no Exemplo 7 - Mover todos os discos da torre A para a torre C, usando a torre B como espaço de manobra.*/

#include <stdio.h>
#include <stdlib.h>
	
int n;
char origem, auxiliar, destino;

void hanoi(n, origem, auxiliar, destino){
	if (n<=0)
		return;
	if (n==1)
		printf( "%d movido de %c para %c\n", n, origem, destino );
	else {
		hanoi( n-1, origem, destino, auxiliar );
		printf( "%d movido de %c para %c\n", n, origem, destino );
		hanoi(n-1, auxiliar, origem, destino);
	}
}

int main(int argc, char *argv[]) {
	
	int n;
	printf("Discos? ");
	scanf("%d", &n);	
	hanoi(n, 'A', 'B', 'C');
	
	return 0;
}