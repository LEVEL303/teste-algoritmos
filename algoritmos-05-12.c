#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho = 5, i, novo_tamanho;
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    printf("Digite o novo tamanho do vetor:\n");
    scanf("%d", &novo_tamanho);

    vetor = (int *) realloc(vetor, novo_tamanho * sizeof(int));

    if(vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    } else {
        printf("Alocacao realizada com sucesso\n");
    }

    printf("Digite os valores do vetor:\n");
    for(i = 0; i < novo_tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Conteudo do vetor:\n");
    for(i = 0; i < novo_tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}