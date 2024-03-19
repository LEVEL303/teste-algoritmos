#include "pilha.h"
#include <stdio.h>

struct no {
    float valor;
    No * prox_no;
};

struct pilha {
    int num_elementos;
    No * topo;
};

float topo(Pilha * pilha) {
    float valor = pilha_pop(pilha);
    pilha_push(pilha, valor);
    return valor;
}

void concatena_pilha(Pilha * pilha1, Pilha * pilha2) {
    Pilha * contador = pilha2->topo;
    while(contador->prox_no != NULL) {
        pilha_push(pilha1, contador->valor);
        contador = contador->prox_no;
    }
}

int main(void) {
    Pilha * pilha = pilha_cria();
    float valor;

    printf("==== Pilha com lista ====\n");

    if(pilha_vazia) {
        printf("Pilha vazia\n");
    }

    pilha_push(pilha, 6.5);
    pilha_push(pilha, 4.4);
    pilha_push(pilha, 5.0);
    pilha_push(pilha, 10.8);
    pilha_push(pilha, 7.1);
    pilha_imprime(pilha);
    
    printf("==============\n");
    
    valor = pilha_pop(pilha);
    pilha_imprime(pilha);

    printf("==============\n");
    printf("%.2f\n", valor);

    pilha_libera(pilha);
    return 0;
}
