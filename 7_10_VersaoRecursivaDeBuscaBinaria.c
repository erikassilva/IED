/*Exercício 10. Versão recursiva de busca binária
Crie a função recursiva rbsearch(x,v,p,u), que faz uma busca binária para determinar
se o item x está no vetor crescente v, indexado de p até u.*/

#include <stdio.h>

int rbsearch(int x, int v[], int p, int u){
	int m;
	m = (p+u)/2;
	if (x == v[m]) return 1;
	else if ( p>u ) return 0;
	if( x < v[m]) return rbsearch(x, v, p, u-1);
	else return rbsearch(x, v, p+1, u);
}

int main (void){
    int v[8] = {19,27,31,48,52,66,75,80};
    printf("27: %d\n", rbsearch(27, v, 0, 7));
    printf("22: %d\n", rbsearch(22, v, 0, 7));
        
    return 0;
}