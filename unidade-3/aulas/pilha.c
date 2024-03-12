#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

#define N 50

struct pilha {
    int n;
    float vet[N];
};

Pilha * pilha_cria(void) {
    Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
    if(pilha == NULL) {
        exit(1);
    }
    pilha->n = 0;
    return pilha;
}

void pilha_push(Pilha * pilha, float valor) {
    if(pilha->n == N) {
        printf("Capaciade da pilha estourou!\n");
        exit(1);
    }
    pilha->vet[pilha->n] = valor;
    pilha->n++;
}

int pilha_vazia(Pilha * pilha) {
    return (pilha->n == 0);
}

float pilha_pop(Pilha * pilha) {
    float valor;
    if(pilha_vazia(pilha)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    valor = pilha->vet[pilha->n-1];
    pilha->n--;
    return valor;
}

void pilha_libera(Pilha * pilha) {
    free(pilha);
}

void pilha_imprime(Pilha * pilha) {
    int index;
    for(index = pilha->n-1; index >= 0; index--) {
        printf("%.2f\n", pilha->vet[index]);
    }
}
