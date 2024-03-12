#include "pilha.h"
#include <stdio.h>

int main() {
    Pilha * pilha;
    float valor;

    pilha = pilha_cria();
    pilha_push(pilha, 3.5);
    pilha_push(pilha, 7.2);
    pilha_push(pilha, 5.3);
    pilha_push(pilha, 4.0);
    pilha_push(pilha, 9.0);

    pilha_imprime(pilha);

    valor = pilha_pop(pilha);
    printf("=== %.2f ===\n", valor);

    pilha_imprime(pilha);

    pilha_libera(pilha);
    
    return 0;
}
