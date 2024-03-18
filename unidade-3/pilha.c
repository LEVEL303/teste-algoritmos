#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

#define N 10

struct pilha {
    int n;
    int limite;
    float * valores;
};

Pilha * pilha_cria(void) {
    Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
    if(pilha == NULL) {
        exit(1);
    }
    pilha->n = 0;
    pilha->limite = N;
    pilha->valores = (float *) malloc(N * sizeof(float));
    if(pilha->valores == NULL) {
        exit(1);
    }
    return pilha;
}

void pilha_push(Pilha * pilha, float valor) {
    if(pilha->n == pilha->limite) {
        int resposta;
        printf("O limite da pilha estourou!\nGostaria de dobrar o limite da pilha? (1-sim 2-nao):\n");
        scanf("%d", &resposta);
        if(resposta == 1) {
            pilha->valores = (float *) realloc(pilha->valores, 2 * pilha->limite * sizeof(float));
            if(pilha->valores == NULL) {
                printf("Erro: Falha na realocacao do vetor!\n");
                exit(1);
            }
            pilha->limite = 2 * pilha->limite;
        } else {
            exit(1);
        }
    }
    pilha->valores[pilha->n] = valor;
    pilha->n++;
}   

int pilha_vazia(Pilha * pilha) {
    if(pilha->n == 0) {
        return 1;
    } else {
        return 0;
    }
}

float pilha_pop(Pilha * pilha) {
    float valor;
    if(pilha_vazia(pilha)) {
        printf("A lista está vazia!\n");
        exit(1);
    }
    valor = pilha->valores[--pilha->n];
    return valor;
}

void pilha_libera(Pilha * pilha) {
    free(pilha->valores);
    free(pilha);
}

void pilha_imprime(Pilha * pilha) {
    int contador;
    for(contador = pilha->n; contador > 0; contador--) {
        printf("%d\n", pilha->valores[contador - 1]);
    }
}
