/*Exercício 2. A função empurra()
Crie a função recursiva empurra(v,i), que “empurra” um item mínimo do vetor v para a
posição i de v, sem alterar a ordem dos demais itens do vetor. Por exemplo, o código abaixo
deve produzir a saída indicada a seguir: 
int v[5] = {48,19,31,52,27};
empurra(v,4);
exibe(v,4);
Saída: {48,31,52,27,19}
*/

#include <stdio.h>

void empurra (int i, int* v){
    int aux = 0;
    for (int j=0; j<i-1; j++)
        if (v[j]>v[j-1]) { 
            int aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            aux = 1;
}
    if (aux != 0)
    empurra (i-1,v);
}

int main (void) {
    int i;
    int v[5] = {48,19,31,52,27};
    empurra (6,v);
    printf("Saida esperada {48,31,52,27,19}: \n");
    for (i=0; i<5; i++)
    printf("%d ",v[i]);
    return 0;
}
