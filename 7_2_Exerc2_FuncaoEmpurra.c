/*Exercício 2. A função empurra()
Crie a função recursiva empurra(v,i), que “empurra” um item mínimo do vetor v para a
posição i de v, sem alterar a ordem dos demais itens do vetor. Por exemplo, o código abaixo
deve produzir a saída indicada a seguir:*/

#include <stdio.h>

void troca (int v[], int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

void empurra (int v [], int n){
    for(int i=1; i<=n; i++)
        for(int j=0; j<=n-i; j++)
            if(v[j] > v[j-1])
                troca(v, j, j-1);
}

void exibe (int v[], int n){
    for(int i=1; i<=n; i++)
        printf("%d ", v[i]);   
}

int main(void){

    int v[5] = {48,19,31,52,27};
    empurra(v, 4);
    exibe(v, 4);

    return 0;
}