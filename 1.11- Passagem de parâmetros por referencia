//Exercício 11. Passagem de parâmetros por referencia

#include <stdio.h>
//A função recebe o endereço da variável passada como entrada
//A função manipula diretamente a variável original que é passada
//As modificações feitas na variável persistem após o término da função (pois a variável é mantida)
//Passagem por referência pode ser mais eficiente, pois não precisa duplicar a variável
//Como o nome de um vetor é o seu endereço, vetores sempre são passados por referência
void troca(int *x, int *y){
	
	int z = *x;
	*x = *y;
	*y = z;

}

int main(void){

	int a= 5, b=8;
	troca(&a, &b);
	printf("a= %d, b= %d\n", a, b);

	return 0;
}

