#include <stdio.h>
#include <stdlib.h>

typedef struct ingresso {
    float preco;
    char local[100];
    char atracao[100];
} Ingresso;

void preencher(Ingresso * ingresso, int i) {
    printf("+++ Ingresso %d +++\n", i+1);
    printf("Informe o preco do ingresso:\n");
    scanf("%f", &ingresso[i].preco);
    printf("Informe o local do evento do ingresso:\n");
    scanf(" %[^\n]s", ingresso[i].local);
    printf("Informe a atracao do ingresso:\n");
    scanf(" %[^\n]s", ingresso[i].atracao);
}

void imprimir(Ingresso * ingresso, int i) {
    printf("=== Dados do ingresso %d ===\n", i+1);
    printf("Preco: %.2f \nLocal: %s \nAtracao: %s \n",
    ingresso[i].preco, ingresso[i].local, ingresso[i].atracao);
    printf("===========================\n");
}

void alteraPreco(Ingresso * ingresso, int i, float novo_valor) {
    ingresso[i].preco = novo_valor;
    printf("Preco do ingresso atualizado com sucesso!\n");
}

void imprimirMenorMaior(Ingresso * ingressos, int quant_ingressos) {
    int i_menor = 0, i_maior = 0, i;
    for(i = 1; i < quant_ingressos; i++) {
        if(ingressos[i].preco < ingressos[i_menor].preco) {
            i_menor = i;
        } 
        if(ingressos[i].preco > ingressos[i_maior].preco) {
            i_maior = i;
        }
    }
    printf("Atracao mais barata:\n");
    imprimir(ingressos, i_menor);
    printf("Atracao mais cara:\n");
    imprimir(ingressos, i_maior);
}

int main() {
    Ingresso * ingressos;
    int quant_ingressos, i, i_novo_valor;
    float novo_valor;

    printf("Informe a quantidade de ingressos:\n");
    scanf("%d", &quant_ingressos);
    ingressos = (Ingresso *) malloc(quant_ingressos * sizeof(Ingresso));

    if(ingressos == NULL) {
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    for(i = 0; i < quant_ingressos; i++) {
        preencher(ingressos, i);
    }
    for(i = 0; i < quant_ingressos; i++) {
        imprimir(ingressos, i);
    }

    printf("Informe o numero de um dos ingressos para atualizar o seu preco:\n");
    scanf("%d", &i_novo_valor);
    printf("Informe um novo preco para o ingresso %d:\n", i_novo_valor);
    scanf("%f", &novo_valor);
    i_novo_valor--;
    alteraPreco(ingressos, i_novo_valor, novo_valor);
    imprimir(ingressos, i_novo_valor);

    imprimirMenorMaior(ingressos, quant_ingressos);
    
    free(ingressos);
    return 0;
}