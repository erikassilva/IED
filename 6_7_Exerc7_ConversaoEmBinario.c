/*Exercício 7. Conversão em binário
Crie a função recursiva binário(n), que
exibe um natural n0 em binário.*/

#include <stdio.h>

void binario(int n){
    if ( n < 2 ) printf("%d", n);
    else{
        binario(n/2);
        printf("%d", n%2);
    }
}

int main(void){
    int n;
    printf("Binario? ");
    scanf("%d", &n);
    binario(n);
    return 0;       
}