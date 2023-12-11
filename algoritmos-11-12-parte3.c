#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[20];
    int idade;
    int matricula;
    char email[50];
};

typedef struct aluno Aluno;

void preencha(Aluno * estudante) {
    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", estudante->nome);

    printf("Digite a sua idade:\n");
    scanf("%d", &estudante->idade);

    printf("Digite a matricula:\n");
    scanf("%d", &estudante->matricula);

    printf("Digite o seu e-mail:\n");
    scanf(" %[^\n]", estudante->email);
}

void imprime(Aluno * estudante) {
    printf("Nome: %s \nIdade: %d \nMatricula: %d\nE-mail: %s\n",
     estudante->nome, estudante->idade, estudante->matricula, estudante->email);
}

int main() {
    Aluno *estudante = (Aluno*) malloc(sizeof(Aluno));
    if(estudante == NULL) {
        exit(1);
    }
    preencha(estudante);

    printf("====================\n");

    imprime(estudante);

    free(estudante);
    return 0;
}