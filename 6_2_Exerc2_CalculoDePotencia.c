//Exercício 2. Cálculo de potência

#include <stdio.h>

float potencia(float x, int n){
    if (n==0) return 1;
    return x*potencia(x, n-1);
}

int main (void){
    float x;
    int n;
    printf("Base e expoente? ");
    scanf("%f %d", &x, &n);
    printf("Potencia = %.1f\n", potencia(x, n));
    return 0;
}