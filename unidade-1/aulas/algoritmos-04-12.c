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
    if(b != 0) {
        return a / b;
    } else {
        printf("Não é possível dividir por 0\n");
        return 0;
    }
}

int calcula(int x, int y, int (*op)(int, int)) {
    return op(x, y);
}

int main() {
    int a = 5;
    increment(&a);
    printf("%d\n", a);
    printf("===================\n");
    int resultado = calcula(8, 0, divisao);
    printf("Resultado: %d\n", resultado);
    return 0;
}