#include <stdio.h>

typedef enum genero {
    MASCULINO,
    FEMININO
}Genero;

typedef struct pessoa {
    char nome[50];
    int idade;
    Genero genero;
}Pessoa;

void preencher(Pessoa *p) {
    printf("Informe o seu nome:\n");
    scanf(" %[^\n]s", p->nome);
    printf("Informe a sua idade:\n");
    scanf("%d", &p->idade);
    printf("Informe o seu genero (0 para masculino ou 1 para feminino):\n");
    int genero;
    do {
        scanf("%d", &genero);
        if (genero != MASCULINO && genero != FEMININO) {
            printf("Genero invalido! Tente novamente:\n");
        }
    }while(genero != MASCULINO && genero != FEMININO);
    p->genero = genero;
}

void imprimir(Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Genero: %s\n", p->genero == MASCULINO ? "Masculino" : "Feminino");
}

int main() {
    Pessoa pessoa;
    preencher(&pessoa);
    imprimir(&pessoa);
    return 0;
}