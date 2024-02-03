#include <stdio.h>
#include <stdlib.h>

#define NOME_ARQUIVO "frutas.txt"

typedef struct fruta {
    char nome[80];
    float preco;
}Fruta;

int main() {
    Fruta fruta;
    FILE * arq_frutas = fopen(NOME_ARQUIVO, "w");
    int continuar;

    if(arq_frutas == NULL) {
        printf("Falha ao abrir '%s'!\n", NOME_ARQUIVO);
        exit(1);
    } else {
        printf("Arquivo '%s' aberto com sucesso.\n", NOME_ARQUIVO);
    }

    do {
        printf("Informe o nome da fruta:\n");
        scanf(" %[^\n]s", fruta.nome);
        fprintf(arq_frutas, "%s, ", fruta.nome);

        printf("Informe o preco da fruta:\n");
        scanf("%f", &fruta.preco);
        fprintf(arq_frutas, "%.2f\n", fruta.preco);

        printf("Inserir mais uma fruta (1-sim 0-nao)?\n");
        scanf("%d", &continuar);
    } while(continuar != 0);

    if(fclose(arq_frutas) == 0) {
        printf("Arquivo '%s' fechado com sucesso.\n", NOME_ARQUIVO);
    }

    printf("Programa encerrado.\n");

    return 0;
}