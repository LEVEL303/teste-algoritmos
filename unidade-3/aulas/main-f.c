#include "fila.h"
#include <stdio.h>

int main() {
    Fila * fila = cria_fila(10);
    int elemento;

    if(fila_vazia(fila)) {
        printf("Fila vazia!\n");
    }

    insere_fila(fila, 43);
    insere_fila(fila, 3);
    insere_fila(fila, 25);
    insere_fila(fila, 75);

    if(fila_cheia(fila)) {
        printf("Fila cheia!\n");
    }

    consulta_fila(fila, &elemento);
    printf("%d\n", elemento);

    remove_fila(fila);

    consulta_fila(fila, &elemento);
    printf("%d\n", elemento);

    destruir_fila(&fila);

    return 0;
}
