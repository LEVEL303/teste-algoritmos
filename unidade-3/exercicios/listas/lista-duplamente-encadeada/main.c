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
    
    insereNoLDE(lista, 3);
    insereNoLDE(lista, 2);
    insereNoLDE(lista, 3);
    insereNoLDE(lista, 1);
    insereNoLDE(lista, 3);

    imprimeListaDE(lista);
    
    if(!listaVazia(lista)) {
        printf("A lista nao esta vazia\n");
    }

    a = buscaNoLDE(lista, 3);
    if(a->info == 3) {
        printf("---- 3 ----\n");
    }

    retiraValorLDE(lista, 3);
    imprimeListaDE(lista);

    liberaListaDE(lista);
    imprimeListaDE(lista);

    return 0;
}