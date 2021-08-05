//Exercício 9. Ponto Struct
//(Registro-armazena uma coleção de itens, que podem ser de tipos distintos)

#include <stdio.h>

typedef struct {float x; float y;} Ponto; //definição de tipo

int main(void){

	Ponto p = {1.2, 2.5}; //declaração de variável
	printf("(%.2f, %.2f)\n",p.x, p.y);

	return 0;
}