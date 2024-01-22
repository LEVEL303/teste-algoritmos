#include <stdio.h>

typedef union dados {
    int meu_int;
    float meu_float;
}Dados;

int main () {
    Dados uniao;
    printf("Digite os dados:\n");
    scanf("%d %f", &uniao.meu_int, &uniao.meu_float);
    printf("Os dados informados: meu_int = %d meu_float = %.2f\n", uniao.meu_int, uniao.meu_float);
    return 0;
}