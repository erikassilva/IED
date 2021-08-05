//Exercicio 12. Média de uma sequência de números

//Alocação dinâmica sequencial usada para armazenar uma coleção de itens em posições adjacentes de memória
//Alocação dinâmica sequencial é feita com vetores dinâmicos, criados com malloc()
//Na alocação dinâmica sequencial o acesso aos itens é rápido, mas inserção e remoção são lentas! 

#include <stdio.h>
#include <stdlib.h>

float media(float v[], int n){

	float s = 0;
	for (int i=0; i<n; i++)
		s += v[i];

	return s/n;
}

int main (void){

	int n;
	printf("quantidade de numeros? ");
	scanf("%d", &n);
	float *v = malloc(n*sizeof(float));
	for (int i=0; i<n; i++){
		printf("%do numero? ", i+1);
		scanf("%f", &v[i]);
	}
	printf("Media = %.2f\n", media(v, n));

	return 0;	
}