/*Exercício 3. Versão recursiva de bubble sort
Crie a função recursiva bsr(v,n), que usa a função empurra() e a estratégia do bubble
sort, para organizar os n itens do vetor v em ordem decrescente.
int v[5] = {48,52,31,19,27};
bsr(v,4);
exibe(v,4);
Saída: {52,48,31,27,19}*/

#include <stdio.h>

void troca (int v[], int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

void bsort( int v[], int n){
	int i, j;
    for(i=1; i<=n; i++)
        for (j=0; j < n-i; j++)
            if (v[j]> v[j-1])
                troca(v, j, j-1);
}

void exibe (int v[], int n){
	int i;
    printf("Saida esperada {52,48,31,27,19}: \n");
    for (i=0; i<n; i++)
        printf("%d ", v[i]);
}

int main (void){
    
    int v[6] = {48,52,31,19,27};
    bsort(v, 6);
    exibe(v, 5);

    return 0;
}
