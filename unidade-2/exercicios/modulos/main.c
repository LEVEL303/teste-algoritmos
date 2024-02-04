#include <stdio.h>
#include "calculadora.h"

int main() {
    int a, b;
    printf("Informe um valor inteiro:\n");
    scanf("%d", &a);
    printf("Informe mais um valor inteiro:\n");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, adicao(a, b));
    printf("%d - %d = %d\n", a, b, subtracao(a, b));
    printf("%d * %d = %d\n", a, b, multiplicacao(a, b));
    printf("%d / %d = %.2f\n", a, b, divisao(a, b));
    printf("%d ^ %d = %d\n", a, b, potenciacao(a, b));

    return 0;
}