#include "listade.h"
#include <stdio.h>

struct listade {
    int info;
    ListaDE * prox_no;
    ListaDE * no_anterior; 
};

int main() {
    ListaDE * lista = criaListaDE();
    ListaDE * a;
    
    lista = insereNoLDE(lista, 3);
    lista = insereNoLDE(lista, 2);
    lista = insereNoLDE(lista, 3);
    lista = insereNoLDE(lista, 1);
    lista = insereNoLDE(lista, 3);

    imprimeListaDE(lista);
    
    if(!listaVazia(lista)) {
        printf("A lista nao esta vazia\n");
    }

    a = buscaNoLDE(lista, 3);
    printf("---- %d ----\n", a->info);

    lista = retiraValorLDE(lista, 3);
    imprimeListaDE(lista);

    liberaListaDE(lista);

    return 0;
}