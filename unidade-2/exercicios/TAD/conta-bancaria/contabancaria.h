#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

/* Define um novo tipo de estrutura dados: ContaBancaria. */
typedef struct contabancaria ContaBancaria;

/* Aloca dinamicamente uma estrutura do tipo ContaBancaria, 
preenche ela com os dados fornecidos via parâmetros e retorna o endereço da estrutura. */
ContaBancaria * criaConta(char titular[], int numero, float saldo);

/* Deposita um valor, especificado via parâmetro, no campo saldo de uma estrutura do tipo
ContaBancaria, fornecida via parâmetro. */
void deposita(ContaBancaria * conta, float valor);

/* Realiza o saque de um valor, especificado via parâmetro, do saldo de uma estrutura
do tipo ContaBancaria, fornecida via parâmetro. */
int saca(ContaBancaria * conta, float valor);

/* Realiza o processo de transferência de um valor, especificado via parâmetro, do saldo 
de uma estrutura do tipo ContaBancaria, fonecida via parâmetro, para o saldo de outra estrutura
do tipo ContaBancaria, também fornecida via parâmetro. */
int transfere(ContaBancaria * origem, ContaBancaria * destino, float valor);

/* Realiza a consulta do saldo de uma estrutura do tipo ContaBancaria, fornecida via parâmetro. */
float saldo(ContaBancaria * conta);

/* Libera a memória alocada de uma estrutura do tipo ContaBancaria, fonecida via parâmetro. */
void excluiConta(ContaBancaria * conta);

#endif