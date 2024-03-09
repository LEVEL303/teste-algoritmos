#include "listade.h"
#include <stdlib.h>
#include <stdio.h>

struct listade {
    int info;
    ListaDE * prox_no;
    ListaDE * no_anterior; 
};

ListaDE * criaListaDE(void) {
    return NULL;
}

int listaVazia(ListaDE * lista) {
    if(lista == NULL) {
        return 1;
    } else {
        return 0;
    }
}

ListaDE * insereNoLDE(ListaDE * lista, int valor) {
    ListaDE * novo_no = (ListaDE *) malloc(sizeof(ListaDE));
    if(novo_no == NULL) {
        exit(1);
    }
    novo_no->info = valor;
    novo_no->prox_no = lista;
    novo_no->no_anterior = NULL;
    
    if(!listaVazia(lista)) {
        lista->no_anterior = novo_no;
    }
    return novo_no;
}

void liberaListaDE(ListaDE * lista) {
    ListaDE * contador = lista;
    ListaDE * no;
    while(contador != NULL) {
        no = contador;
        contador = contador->prox_no;
        free(no);
    }
}

ListaDE * buscaNoLDE(ListaDE * lista, int valor) {
    ListaDE * contador;
    for(contador = lista; contador != NULL; contador = contador->prox_no) {
        if(contador->info == valor) {
            return contador;
        }
    }
    return NULL;
}

ListaDE * retiraValorLDE(ListaDE * lista, int valor) {
    if(lista != NULL) {
        ListaDE * contador = lista;
        ListaDE * no;

        while(contador != NULL) {
            if(contador->info == valor) {
                if(contador->no_anterior == NULL && contador->prox_no == NULL) {
                    lista = NULL;
                } else if(contador->no_anterior == NULL) {
                    contador->prox_no->no_anterior = contador->no_anterior;
                    lista = contador->prox_no;
                } else if(contador->prox_no == NULL) {
                    contador->no_anterior->prox_no = contador->prox_no;
                } else {
                    contador->no_anterior->prox_no = contador->prox_no;
                    contador->prox_no->no_anterior = contador->no_anterior;
                }
                no = contador;
                contador = contador->prox_no;
                free(no);
            }
        }
    }
    return lista;
}

void imprimeListaDE(ListaDE * lista) {
    ListaDE * contador;
    for(contador = lista; contador != NULL; contador = contador->prox_no) {
        printf("%d\n", contador->info);
    }
}