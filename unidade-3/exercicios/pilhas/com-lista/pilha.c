#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

struct no {
    float valor;
    No * prox_no;
};

struct pilha {
    int num_elementos;
    No * topo;
};

Pilha * pilha_cria(void) {
    Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
    if(pilha == NULL) {
        exit(1);
    }
    pilha->num_elementos = 0;
    pilha->topo = NULL;
    return pilha;
}

void pilha_push(Pilha * pilha, float valor) {
    if(pilha->num_elementos == MAX) {
        printf("O limite da pilha estourou!\n");
        exit(1);
    }
    No * novo_no = (No *) malloc(sizeof(No));
    if(novo_no == NULL) {
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->prox_no = pilha->topo;
    pilha->topo = novo_no;
    pilha->num_elementos++;
}

int pilha_vazia(Pilha * pilha) {
    if(pilha->num_elementos == 0) {
        return 1;
    } 
    return 0;
}

float pilha_pop(Pilha * pilha) {
    float valor;
    No * no;
    if(pilha_vazia(pilha)) {
        printf("A pilha esta vazia!\n");
        return 0;
    }
    valor = pilha->topo->valor;
    no = pilha->topo;
    pilha->topo = pilha->topo->prox_no;
    free(no);
    return valor;
}

void pilha_libera(Pilha * pilha) {
    No * no;
    while(pilha->topo != NULL) {
        no = pilha->topo;
        pilha->topo = pilha->topo->prox_no;
        free(no);
    }
    free(pilha);
}

void pilha_imprime(Pilha * pilha) {
    No * contador;
    for(contador = pilha->topo; contador != NULL; contador = contador->prox_no) {
        printf("%.2f\n", contador->valor);
    }
}