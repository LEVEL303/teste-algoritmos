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

Lista * busca_elemento(Lista * lista, int valor) {
    Lista * contador;
    for(contador = lista; contador != NULL; contador = contador->prox_elemento) {
        if(contador->info == valor) {
            return contador;
        }
    }
    return NULL;
}

Lista * deleta_elemento(Lista * lista, Lista * no) {
    if(lista != NULL && no != NULL) {
        Lista * contador;
        Lista * no_anterior = NULL;

        for(contador = lista; contador != no; contador = contador->prox_elemento) {
            no_anterior = contador;
        }
        if(no_anterior != NULL) {
            no_anterior->prox_elemento = no->prox_elemento;
        } else {
            lista = no->prox_elemento;
        }
        free(no);
        return lista;
    }
}

int maiores(Lista * lista, int valor) {
    int elementos_maiores = 0;
    Lista * contador;

    for(contador = lista; contador != NULL; contador = contador->prox_elemento) {
        if(contador->info > valor) {
            elementos_maiores++;
        }
    }
    return elementos_maiores;
}

Lista * ultimo(Lista * lista) {
    Lista * contador = lista;

    while(contador->prox_elemento != NULL) {
        contador = contador->prox_elemento;
    }
    return contador;
}

Lista * concatena(Lista * lista_1, Lista * lista_2) {
    Lista * ultimo_elemento = ultimo(lista_1);
    ultimo_elemento->prox_elemento = lista_2;
    return lista_1;
}

Lista * retira_valor(Lista * lista, int valor) {
    Lista * contador = lista;
    Lista * no;

    while(contador != NULL) {
        if(contador->info == valor) {
            no = contador;
            contador = contador->prox_elemento;
            lista = deleta_elemento(lista, no);
        } else {
            contador = contador->prox_elemento;
        }
    }
    
    return lista;
}