#include <stdio.h>

typedef enum tipoproduto {
    ALIMENTO = 1,
    BEBIDA,
    ELETRONICO
}TipoProduto;

typedef struct produto {
    char nome[50];
    float preco;
    TipoProduto tipo_produto;
}Produto;

void preencherProduto(Produto * produto) {
    printf("Informe o nome do produto:\n");
    scanf(" %[^\n]s", produto->nome);
    printf("Informe o preco do produto:\n");
    scanf("%f", &produto->preco);
    printf("Informe o tipo do produto (1 para ALIMENTO, 2 para BEBIDA ou 3 para ELETRONICO):\n");
    int tipo_produto;
    do {
        scanf("%d", &tipo_produto);
        if(tipo_produto != ALIMENTO && tipo_produto != BEBIDA && tipo_produto != ELETRONICO) {
            printf("Tipo de produto invalido! Tente novamente:\n");
        }
    } while(tipo_produto != ALIMENTO && tipo_produto != BEBIDA && tipo_produto != ELETRONICO);
    produto->tipo_produto = tipo_produto;
}

void imprimirProduto(Produto * produto) {
    printf("Nome do produto: %s\n", produto->nome);
    printf("Preco do produto: %.2f\n", produto->preco);
    if(produto->tipo_produto == ALIMENTO) {
        printf("Tipo do produto: ALIMENTO\n");
    } else if (produto->tipo_produto == BEBIDA) {
        printf("Tipo do produto: BEBIDA\n");
    } else if (produto->tipo_produto == ELETRONICO) {
        printf("Tipo do produto: ELETRONICO\n");
    }
}

int main() {
    Produto produto;
    preencherProduto(&produto);
    imprimirProduto(&produto);
    return 0;
}