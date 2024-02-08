#include "contabancaria.h"
#include <stdio.h>

int main() {
    ContaBancaria * conta1 = criaConta("Teste 1", 123, 1200.00);
    ContaBancaria * conta2 = criaConta("Teste 2", 567, 800.75);
    
    printf("Titular: %s \nNumero: %d \nSaldo: %.2f\n",
    conta1->titular, conta1->numero, conta1->saldo);
    
    deposita(conta1, 250.20);
    saca(conta2, 100.00);
    transfere(conta1, conta2, 400);
    printf("Saldo da conta1: %.2f \n Saldo da conta2: %.2f\n", saldo(conta1), saldo(conta2));
    
    excluiConta(conta1);
    excluiConta(conta2);
    
    return 0;
}