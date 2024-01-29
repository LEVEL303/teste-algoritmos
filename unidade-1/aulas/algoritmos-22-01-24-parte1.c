#include <stdio.h>
#include <stdlib.h>

typedef union documento {
    char rg[15];
    char cpf[15];
}Documento;

typedef struct pessoa {
    char nome[50];
    int idade;
    Documento doc;
}Pessoa;

void dados_pessoa(Pessoa *p) {
    int opcao;
    printf("Informe o nome:\n");
    scanf(" %[^\n]s", p->nome);
    printf("Informe a idade:\n");
    scanf("%d", &p->idade);
    printf("Digite 1 para o RG ou digite 0 para o CPF:\n");
    scanf("%d", &opcao);
    if(opcao) {
        printf("Informe o RG:\n");
        scanf(" %s", p->doc.rg);
    } else {
        printf("Informe o CPF:\n");
        scanf(" %s", p->doc.cpf);
    }
}

int main() {
    Pessoa * pessoa = (Pessoa *) malloc(sizeof(Pessoa));
    if(pessoa == NULL) {
        exit(1);
    }
    dados_pessoa(pessoa);
    printf("CPF = %s \nRG = %s\n", pessoa->doc.cpf, pessoa->doc.rg);
    free(pessoa);
    return 0;
}