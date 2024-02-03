#include <stdio.h>
#include <stdlib.h>

#define QUANT_NUMEROS 10
#define NOME_ARQUIVO_ENTRADA "entrada-2.txt"
#define NOME_ARQUIVO_SAIDA "saida-2.txt"

int main() {
    FILE * arq_entrada = fopen(NOME_ARQUIVO_ENTRADA, "r");
    FILE * arq_saida = fopen(NOME_ARQUIVO_SAIDA, "wt");
    int * numeros = (int *) malloc(QUANT_NUMEROS * sizeof(int));
    int index, index_maior = 0, index_menor = 0;
    float media = 0;

    if(arq_entrada == NULL) {
        printf("Falha ao abrir o arquivo '%s'!\n", NOME_ARQUIVO_ENTRADA);
        exit(1);
    } else {
        printf("Arquivo '%s' aberto com sucesso.\n", NOME_ARQUIVO_ENTRADA);
    }
    if(arq_saida == NULL) {
        printf("Falha ao abrir o arquivo '%s'!\n", NOME_ARQUIVO_SAIDA);
        exit(1);
    } else {
        printf("Arquivo '%s' aberto com sucesso.\n", NOME_ARQUIVO_SAIDA);
    }

    if(numeros == NULL) {
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    }

    for(index = 0; index < QUANT_NUMEROS; index++) {
        fscanf(arq_entrada, "%d", &numeros[index]);
    }

    for(index = 1; index < QUANT_NUMEROS; index++) {
        if(numeros[index] > numeros[index_maior]) {
            index_maior = index;
        }
        if(numeros[index] < numeros[index_menor]) {
            index_menor = index;
        }
    }

    for(index = 0; index < QUANT_NUMEROS; index++) {
        media = media + numeros[index];
    }
    media = media / QUANT_NUMEROS;

    fprintf(arq_saida, "Menor elemento: %d \nMaior elemento: %d \nMedia dos elementos: %.2f\n", 
    numeros[index_menor], numeros[index_maior], media);

    if(fclose(arq_entrada) == 0) {
        printf("Arquivo '%s' fechado com sucesso.\n", NOME_ARQUIVO_ENTRADA);
    }
    if(fclose(arq_saida) == 0) {
        printf("Arquivo '%s' fechado com sucesso.\n", NOME_ARQUIVO_SAIDA);
    }

    free(numeros);
    return 0;
}