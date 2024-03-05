#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Criando uma lista encadeada
    Lista * lista_encadeada = cria_lista();
    Lista * no;

    lista_encadeada = insere_elemento(lista_encadeada, 3);
    lista_encadeada = insere_elemento(lista_encadeada, 4);
    lista_encadeada = insere_elemento(lista_encadeada, 1);

    imprime_lista(lista_encadeada);

    if(lista_vazia(lista_encadeada)) {
        printf("A lista esta vazia\n");
    }

    no = busca_elemento(lista_encadeada, 1);
    if(no == NULL) {
        printf("elemento nao encontrado\n");
    }

    deleta_elemento(lista_encadeada, no);
    
    printf("==================\n");
    imprime_lista(lista_encadeada);

    return 0;
}