#include "lista.h"

int main() {
    //Criando uma lista encadeada
    Lista * lista_encadeada = cria_lista();
    lista_encadeada = insere_elemento(lista_encadeada, 3);
    lista_encadeada = insere_elemento(lista_encadeada, 2);
    lista_encadeada = insere_elemento(lista_encadeada, 1);

    imprime_lista(lista_encadeada);

    return 0;
}