#include "lista.h"
#include <stdio.h>

struct lista {
    int info;
    Lista * prox_elemento;
};

int main() {
    Lista * lista_1 = cria_lista();
    Lista * lista_2 = cria_lista();
    Lista * lista_3 = cria_lista();
    Lista * ultimo_elemento;
    int elementos_maiores;
    int valor;
    
    lista_1 = insere_elemento(lista_1, 3);
    lista_1 = insere_elemento(lista_1, 4);
    lista_1 = insere_elemento(lista_1, 2);

    printf("Informe um valor:\n");
    scanf("%d", &valor);

    lista_1 = insere_elemento(lista_1, valor);

    elementos_maiores = maiores(lista_1, valor);
    printf("Ha %d elementos maiores que %d na lista 1\n", elementos_maiores, valor);
        
    printf("==== Lista 1 ====\n");
    imprime_lista(lista_1);

    ultimo_elemento = ultimo(lista_1);
    printf("Ultimo elemento da lista 1: %d\n", ultimo_elemento->info);

    lista_2 = insere_elemento(lista_2, 1);
    lista_2 = insere_elemento(lista_2, 1);
    lista_2 = insere_elemento(lista_2, 3);
    lista_2 = insere_elemento(lista_2, 1);
    lista_2 = insere_elemento(lista_2, 9);
    lista_2 = insere_elemento(lista_2, 0);

    printf("==== Lista 2 ====\n");
    imprime_lista(lista_2);

    lista_3 = concatena(lista_1, lista_2);
    printf("==== Lista 3 ====\n");
    imprime_lista(lista_3);

    lista_3 = retira_valor(lista_3, 1);
    printf("====================\n");
    imprime_lista(lista_3);

    return 0;
}