#include <stdio.h>
#include <stdlib.h>

#define NOME_ARQUIVO "saida-exercicio-1.txt"

typedef struct funcionario {
    int id;
    char nome[80];
    float salario;
}Funcionario;

int main() {
    FILE * arq_saida = fopen(NOME_ARQUIVO, "a");
    Funcionario funcionario;

    if(arq_saida == NULL) {
        printf("Falha ao tentar abrir o arquivo %s!\n", NOME_ARQUIVO);
        exit(1);
    } else {
        printf("Arquivo %s aberto com sucesso.\n", NOME_ARQUIVO);
    }

    printf("Informe o seu id:\n");
    scanf("%d", &funcionario.id);
    printf("Informe o seu nome:\n");
    scanf(" %[^\n]s", funcionario.nome);
    printf("Informe o seu salario:\n");
    scanf("%f", &funcionario.salario);

    fprintf(arq_saida, "Id: %d, Nome: %s, Salário: %.2f\n",
    funcionario.id, funcionario.nome, funcionario.salario);

    if(fclose(arq_saida) == 0) {
        printf("Arquivo %s fechado com sucesso.\n", NOME_ARQUIVO);
    }

    return 0;
}