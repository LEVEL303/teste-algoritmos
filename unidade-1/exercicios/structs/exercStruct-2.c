#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char nome[50];
    int documento;
    int idade;
} Pessoa;

void preencher(Pessoa *pessoas, int nPessoas) {
    int contador;
    for(contador = 0; contador < nPessoas; contador++) {
        printf("++++++++++++++++++++++++\n");
        printf("Nome:\n");
        scanf(" %[^\n]s", pessoas[contador].nome);
        printf("Numero do documento:\n");
        scanf("%d", &pessoas[contador].documento);
        printf("Idade:\n");
        scanf("%d", &pessoas[contador].idade);
    }
}

void imprimir(Pessoa *pessoas, int nPessoas) {
    int contador;
    for(contador = 0; contador < nPessoas; contador++) {
        printf("=======================\n");
        printf("Nome: %s \nNumero do documento: %d \nIdade: %d \n",
         pessoas[contador].nome, pessoas[contador].documento, pessoas[contador].idade);
    }
}

void alterarIdade(Pessoa *pessoas, int indice) {
    printf("Nova Idade de %s:\n", pessoas[indice].nome);
    scanf("%d", &pessoas[indice].idade);
}

void maiorMenorIdade(Pessoa *pessoas, int nPessoas) {
    int indiceMaiorIdade = 0;
    int indiceMenorIdade = 0;
    int contador;
    for(contador = 1; contador < nPessoas; contador++) {
        if(pessoas[contador].idade > pessoas[indiceMaiorIdade].idade) {
            indiceMaiorIdade = contador;
        }
        if(pessoas[contador].idade < pessoas[indiceMenorIdade].idade) {
            indiceMenorIdade = contador;
        }
    }
    printf("Pessoa com maior idade: %s\n", pessoas[indiceMaiorIdade].nome);
    printf("Pessoa com menor idade: %s\n", pessoas[indiceMenorIdade].nome);
}

int main() {
    int nPessoas;
    printf("Numero de pessoas:\n");
    scanf("%d", &nPessoas);
    Pessoa *pessoas = (Pessoa *) malloc(nPessoas * sizeof(Pessoa));
    if(pessoas == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }
    preencher(pessoas, nPessoas);
    imprimir(pessoas, nPessoas);
    printf("=======================\n");
    alterarIdade(pessoas, 0);
    printf("=======================\n");
    maiorMenorIdade(pessoas, nPessoas);
 
    free(pessoas);
    return 0;
}