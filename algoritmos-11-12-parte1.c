#include <stdio.h>

struct aluno {
    char nome[20];
    int idade;
    int matricula;
    char email[50];
};

int main() {
    struct aluno estudante;
    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", estudante.nome);

    printf("Digite a sua idade:\n");
    scanf("%d", &estudante.idade);

    printf("Digite a matricula:\n");
    scanf("%d", &estudante.matricula);

    printf("Digite o seu e-mail:\n");
    scanf(" %[^\n]", estudante.email);
    return 0;
}