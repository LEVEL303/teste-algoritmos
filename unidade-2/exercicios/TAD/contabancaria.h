#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct contabancaria ContaBancaria;

ContaBancaria * criaConta(char titular[], int numero, float saldo);
void deposita(ContaBancaria * conta, float valor);
int saca(ContaBancaria * conta, float valor);
int transfere(ContaBancaria * origem, ContaBancaria * destino, float valor);
float saldo(ContaBancaria * conta);
void excluiConta(ContaBancaria * conta);

#endif