#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[20];
    int idade;
    int matricula;
    char email[50];
};

int main() {
    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));
    if(estudante == NULL) {
        exit(1);
    }
    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", estudante->nome);

    printf("Digite a sua idade:\n");
    scanf("%d", &estudante->idade);

    printf("Digite a matricula:\n");
    scanf("%d", &estudante->matricula);

    printf("Digite o seu e-mail:\n");
    scanf(" %[^\n]", estudante->email);
    free(estudante);
    return 0;
}