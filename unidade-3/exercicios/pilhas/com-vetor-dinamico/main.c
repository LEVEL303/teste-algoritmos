#include "pilha.h"
#include <stdio.h>

int main(void) {
    Pilha * pilha = pilha_cria();
    float valor;

    printf("==== Pilha com vetor dinamico ====\n");

    if(pilha_vazia) {
        printf("Pilha vazia\n");
    }

    pilha_push(pilha, 1.5);
    pilha_push(pilha, 2.4);
    pilha_push(pilha, 3.0);
    pilha_push(pilha, 7.8);
    pilha_push(pilha, 8.1);
    pilha_imprime(pilha);
    
    printf("==============\n");
    
    valor = pilha_pop(pilha);
    pilha_imprime(pilha);

    printf("==============\n");
    printf("%.2f\n", valor);

    pilha_libera(pilha);
    return 0;
}
