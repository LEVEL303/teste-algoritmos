#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct fila {
    int inicio, fim;
    int quant_elementos;
    int tamanho_max;
    int * valor;
};

Fila * cria_fila(int tamanho_max) {
    Fila * fila = (Fila *) calloc(1, sizeof(Fila));

    fila->valor = (int *) calloc(tamanho_max, sizeof(int));
    fila->tamanho_max = tamanho_max;
    fila->quant_elementos = 0;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

void destruir_fila(Fila ** fila) {
    Fila * fauxi = * fila;
    free(fauxi->valor);
    free(fauxi);
    * fila = NULL;
}

int fila_vazia(Fila * fila) {
    return (fila->quant_elementos == 0);
}

int fila_cheia(Fila * fila) {
    return (fila->quant_elementos == fila->tamanho_max);
}

int insere_fila(Fila * fila, int valor) {
    if(fila_cheia(fila)) {
        printf("Erro: Fila cheia\n");
        return 0;
    } else {
        fila->valor[fila->fim] = valor;
        fila->fim = (fila->fim + 1) % fila->tamanho_max;
        fila->quant_elementos++;
        return 1;
    }
}

int remove_fila(Fila * fila) {
    if(fila_vazia(fila)) {
        printf("Erro: Fila vazia\n");
        return 0;
    } else {
        fila->inicio = (fila->inicio + 1) % fila->tamanho_max;
        fila->quant_elementos--;
        return 1;
    }
}

int consulta_fila(Fila * fila, int * elemento) {
    if(fila_vazia(fila)) {
        printf("Erro: Fila vazia\n");
        return 0;
    } else {
        * elemento = fila->valor[fila->inicio];
        return 0;
    }
}
