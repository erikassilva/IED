//Exercício 10. Passagem de parâmetros por valor

#include <stdio.h>

//A função recebe o valor da variável passada como entrada
//A função manipula apenas uma cópia da variável que é passada
//As modificações feitas na variável são perdidas após o término da função (pois a cópia é destruída)
//Passagem por valor é mais segura; porém, consome mais tempo e espaço

void troca(int x, int y){ 
	int z = x;
	x = y;
	y = z;
}

int main(void){

	int a=5, b=8;
	troca(a,b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}