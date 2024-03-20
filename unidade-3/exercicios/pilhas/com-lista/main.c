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
    No * contador = pilha2->topo;
    while(contador != NULL) {
        pilha_push(pilha1, contador->valor);
        contador = contador->prox_no;
    }
    pilha_libera(pilha2);
}

int main(void) {
    Pilha * pilha1 = pilha_cria();
    Pilha * pilha2 = pilha_cria();
    float valor;

    printf("==== Pilha com lista ====\n");

    if(pilha_vazia(pilha1)) {
        printf("Pilha vazia\n");
    }

    pilha_push(pilha1, 6.5);
    pilha_push(pilha1, 4.4);
    pilha_push(pilha1, 5.0);
    pilha_push(pilha1, 10.8);
    pilha_push(pilha1, 7.1);
    pilha_imprime(pilha1);
    
    printf("==============\n");
    
    valor = pilha_pop(pilha1);
    pilha_imprime(pilha1);

    printf("==============\n");
    printf("%.2f\n", valor);

    printf("====== + ======\n");
    valor = topo(pilha1);
    printf("* %.2f\n", valor);
    pilha_imprime(pilha1);

    printf("=== Pilha 2 ===\n");
    pilha_push(pilha2, 34.3);
    pilha_push(pilha2, 3.0);
    pilha_push(pilha2, 2.1); 
    pilha_imprime(pilha2);

    printf("=== concatenação ===\n");
    concatena_pilha(pilha1, pilha2);
    pilha_imprime(pilha1);

    pilha_libera(pilha1);
    pilha_libera(pilha2);
    return 0;
}
