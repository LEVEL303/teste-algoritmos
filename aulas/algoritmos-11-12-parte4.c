#include <stdio.h>
#include <stdlib.h>

typedef struct professor {
    char nome[20];
    int idade;
    int matricula;
    char disciplina[50];
    char email[50];
}Professor;

void preencha(Professor * docente) {
    printf("Digite o seu nome:\n");
    scanf(" %[^\n]", docente->nome);

    printf("Digite a sua idade:\n");
    scanf("%d", &docente->idade);

    printf("Digite a matricula:\n");
    scanf("%d", &docente->matricula);

    printf("Digite a disciplina:\n");
    scanf(" %[^\n]", docente->disciplina);

    printf("Digite o seu e-mail:\n");
    scanf(" %[^\n]", docente->email);
}

void imprime(Professor * docente) {
    printf("Nome: %s \nIdade: %d \nMatricula: %d \nDisciplina %s \nE-mail: %s \n",
     docente->nome, docente->idade, docente->matricula, docente->disciplina, docente->email);
}

int main() {
    Professor *docente = (Professor*) malloc(sizeof(Professor));
    if(docente == NULL) {
        exit(1);
    }
    preencha(docente);

    printf("====================\n");

    imprime(docente);

    free(docente);
    return 0;
}