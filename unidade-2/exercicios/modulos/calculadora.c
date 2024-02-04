#include "calculadora.h"

int adicao(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

float divisao(int a, int b) {
    if(b != 0) {
        return a / b;
    } else {
        return 0.0;
    }
}

float potenciacao(int a, int b) {
    int index;
    float resultado = 1.0;
    if(b >= 0) {
        for(index = 1; index <= b; index++) {
            resultado = resultado * a;
        }
        return resultado;
    } else { 
        for(index = -1; index >= b; index--) {
            resultado = resultado * a;
        }
        return 1 / resultado;
    }
}