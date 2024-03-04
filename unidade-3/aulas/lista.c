#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct lista {
    int info;
    Lista * prox_elemento;
};

Lista * cria_lista() {
    return NULL;
}

Lista * insere_elemento(Lista * lista, int valor) {
    Lista * novo_no = (Lista *) malloc(sizeof(Lista));
    if(novo_no == NULL) {
        exit(1);
    }
    novo_no->info = valor;
    novo_no->prox_elemento = lista;
    return novo_no;
}

void imprime_lista(Lista * lista) {
    Lista * contador;
    for(contador = lista; contador != NULL; contador = contador->prox_elemento) {
        printf("%d\n", contador->info);
    }
}

int lista_vazia(Lista * lista) {
    if(lista == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Lista busca(Lista * lista, int valor) {
    Lista * contador;
    for(contador = lista; contador != NULL; contador = contador->prox_elemento) {
        if(contador->info == valor) {
            return contador;
        }
    }
    return NULL;
}

// função pra retirar um elemento da lista