#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[50];
    float salario;
    int identificador;
    char cargo[40];
} Funcionario;

void preencher(Funcionario *empregado, int nFuncionarios) {
    int contador;
    for(contador = 0; contador < nFuncionarios; contador++) {
        printf("++++++++++++++++++++++++++++++\n");
        printf("Nome:\n");
        scanf(" %[^\n]s", empregado[contador].nome);

        printf("Salario:\n");
        scanf("%f", &empregado[contador].salario);

        printf("Identificador:\n");
        scanf("%d", &empregado[contador].identificador);
        
        printf("Cargo:\n");
        scanf(" %[^\n]s", empregado[contador].cargo);
    }
}

void imprimir(Funcionario *empregado, int nFuncionarios) {
    int contador;
    for(contador = 0; contador < nFuncionarios; contador++) { 
        printf("=============================\n");
        printf("Nome: %s \nSalario: %.2f \nIdentificador: %d \nCargo: %s \n",
        empregado[contador].nome, empregado[contador].salario, empregado[contador].identificador, empregado[contador].cargo);
    }
}

void alterarSalario(Funcionario *empregado, int indice) {
    printf("Novo salario de %s:\n", empregado[indice].nome);
    scanf("%f", &empregado[indice].salario);
}

void maiorMenor(Funcionario *empregado, int nFuncionarios) {
    int indiceMaiorSalario = 0;
    int indiceMenorSalario = 0;
    int contador;
    for(contador = 1; contador < nFuncionarios; contador++) {
        if(empregado[contador].salario > empregado[indiceMaiorSalario].salario) {
            indiceMaiorSalario = contador;
        }
        if(empregado[contador].salario < empregado[indiceMenorSalario].salario) {
            indiceMenorSalario = contador;
        }
    }
    printf("Funcionario com o maior salario: \nCargo: %s \nSalario: %.2f\n",
     empregado[indiceMaiorSalario].cargo, empregado[indiceMaiorSalario].salario);
    printf("Funcionario com o menor salario: \nCargo: %s \nSalario: %.2f\n",
     empregado[indiceMenorSalario].cargo, empregado[indiceMenorSalario]. salario);
}

int main() {
    int nFuncionarios;
    printf("Numero de funcionarios:\n");
    scanf("%d", &nFuncionarios);
    Funcionario *empregado = (Funcionario *) malloc(nFuncionarios * sizeof(Funcionario));
    if(empregado == NULL) {
        printf("Erro de alocacao de memoria.");
        exit(1);
    }
    preencher(empregado, nFuncionarios);
    imprimir(empregado, nFuncionarios);
    printf("========================\n");
    alterarSalario(empregado, 0);
    printf("========================\n");
    maiorMenor(empregado, nFuncionarios);

    free(empregado);
    return 0;
}