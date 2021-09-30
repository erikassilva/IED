/*Exercício 6. Ordenação por intercalação decrescente
Crie uma versão da função de ordenação por intercalação, denominada msortd(), que usa a
função intercalad() para ordenar um vetor em ordem decrescente*/

#include <stdio.h>

void intercalad (int v[], int p, int m, int u){
    int w[u-p+1];
    int i=p, j=m+1, k=0;
    while( i<=m && j<=u )
        if (v[i] > v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    while( i<=m ) w[k++] = v[i++];
    while( j<=u ) w[k++] = v[j++];
    for( k=0; k<=u-p; k++) v[p+k] = w[k];
}

void ms(int v[], int p, int u){
    if( p==u ) return;
    int m = (p+u)/2;
    ms(v,p,m);
    ms(v, m+1, u);
    intercalad (v,p, m, u);
}

void msortd (int v[], int n){
    ms(v, 0, n-1);
}

void exibe (int v[], int n){
	int i;
    for (i=0; i<n; i++)
        printf("%d ", v[i]);
}

int main (void){
    int v[10] = {83,31,91,46,27,20,96,25,96,80};
    msortd(v, 10);
    exibe(v,10);
    return 0;
}