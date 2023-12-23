#include <stdio.h>

void increment(int *v) {
    (*v)++;
}

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

int divisao(int a, int b) {
    return a / b;
}

int calcula(int x, int y, int (*op)(int, int)) {
    return (*op)(x, y);
}

int main() {
    int a = 5;
    increment(&a);
    printf("%d\n", a);
    printf("===================\n");
    int resultado = calcula(8, 2, soma);
    printf("Resultado: %d", resultado);
    return 0;
}