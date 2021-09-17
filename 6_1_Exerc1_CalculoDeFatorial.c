//Exercício 01 - Cálculo de fatorial

#include <stdio.h>

int fat(int n) {
    if(n == 0) return 1;
    return n*fat(n-1);
}

int main(void){
    int n;
    printf("num? ");
    scanf("%d", &n);
    printf("Fat = %d\n", fat(n));
    return 0;
}