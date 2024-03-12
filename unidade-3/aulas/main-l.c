#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Criando uma lista encadeada
    Lista * lista_encadeada = cria_lista();
    Lista * no;
    int elemento;

    lista_encadeada = insere_elemento(lista_encadeada, 3);
    lista_encadeada = insere_elemento(lista_encadeada, 4);
    lista_encadeada = insere_elemento(lista_encadeada, 1);

    imprime_lista(lista_encadeada);

    if(lista_vazia(lista_encadeada)) {
        printf("A lista esta vazia\n");
    }

    printf("Digite um elemento da lista para ser deletado:\n");
    scanf("%d", &elemento);

    no = busca_elemento(lista_encadeada, elemento);
    if(no == NULL) {
        printf("elemento nao encontrado\n");
    }

    lista_encadeada = deleta_elemento(lista_encadeada, no);
    
    printf("==================\n");
    imprime_lista(lista_encadeada);

    return 0;
}