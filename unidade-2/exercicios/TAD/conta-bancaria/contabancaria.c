#include "contabancaria.h"
#include <stdlib.h>
#include <string.h>

struct contabancaria {
    char titular[80];
    int numero;
    float saldo;
};

ContaBancaria * criaConta(char titular[], int numero, float saldo) {
    ContaBancaria * conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
    if(conta == NULL) {
        exit(1);
    }
    strcpy(conta->titular, titular);
    conta->numero = numero;
    conta->saldo = saldo;
    
    return conta;
}

void deposita(ContaBancaria * conta, float valor) {
    conta->saldo += valor;
}

int saca(ContaBancaria * conta, float valor) {
    if(conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1;
    }
    return 0;
}

int transfere(ContaBancaria * origem, ContaBancaria * destino, float valor) {
    if(saca(origem, valor)) {
        deposita(destino, valor);
        return 1;
    }
    return 0;
}

float saldo(ContaBancaria * conta) {
    return conta->saldo;
}

void excluiConta(ContaBancaria * conta) {
    free(conta);
}