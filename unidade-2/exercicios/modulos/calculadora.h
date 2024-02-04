#ifndef CALCULADORA_H
#define CALCULADORA_H

int adicao(int a, int b);
// Realiza a operação de adição dos números inteiros "a" e "b".

int subtracao(int a, int b);
// Realiza a operação de subtração do número inteiro "a" pelo número inteiro "b".

int multiplicacao(int a, int b);
// Realiza a operação de multiplicação do número inteiro "a" pelo número inteiro "b".

float divisao(int a, int b);
/* Realiza a operação de divisão do número inteiro "a" pelo número inteiro "b", sendo "b" diferente de 0,
e retorna um valor do tipo float. Se "b" for igual a 0 o resultado será: 0.0. */

float potenciacao(int a, int b);
// Realiza a operação de pontenciação do número inteiro "a" pelo número inteiro "b" (retorna um valor float).

#endif