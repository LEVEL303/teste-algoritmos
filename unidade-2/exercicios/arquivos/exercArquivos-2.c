#include <stdio.h>
#include <stdlib.h>

#define QUANT_NUMEROS 10

int main() {
    FILE * arq_entrada = fopen("entrada-2.txt", "r");
    FILE * arq_saida = fopen("saida-2.txt", "wt");
    int * numeros = (int *) malloc(QUANT_NUMEROS * sizeof(int));
    int index, index_maior = 0, index_menor = 0;
    float media = 0;

    if(arq_entrada == NULL) {
        printf("Falha ao abrir o arquivo 'entrada-2.txt'!\n");
        exit(1);
    } else {
        printf("Arquivo 'entrada-2.txt' aberto com sucesso.\n");
    }
    if(arq_entrada == NULL) {
        printf("Falha ao abrir o arquivo 'saida-2.txt'!\n");
        exit(1);
    } else {
        printf("Arquivo 'saida-2.txt' aberto com sucesso.\n");
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

    fprintf(arq_saida, "Menor elemento: %d \nMaior elemento: %d \nMedia dos elementos: %f\n", 
    numeros[index_menor], numeros[index_maior], media);

    if(fclose(arq_entrada) == 0) {
        printf("Arquivo 'entrada-2.txt' fechado com sucesso.\n");
    }
    if(fclose(arq_saida) == 0) {
        printf("Arquivo 'saida-2.txt' fechado com sucesso.\n");
    }

    free(numeros);
    return 0;
}