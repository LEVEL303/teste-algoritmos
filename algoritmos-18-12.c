#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina {
    char nome[40];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno {
    char nome[50];
    int idade;
    long int matricula;
    Disciplina *materias;
} Aluno;

int main() {
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
    if(aluno == NULL) {
        exit(1);
    }
    aluno->materias = (Disciplina *) malloc(2 * sizeof(Disciplina));
    if(aluno->materias == NULL) {
        exit(1);
    }
    printf("Informe os dados do aluno: nome, idade e matricula\n");
    scanf("%[^\n]", aluno->nome);
    scanf("%d %ld", &aluno->idade, &aluno->matricula);
    int contador;
    for(contador = 0; contador < 2; contador++) {
        printf("Cadastro da disciplina %d:\n", contador+1);
        printf("Nome:\n");
        scanf(" %[^\n]", aluno->materias[contador].nome);
        printf("Nota:\n");
        scanf("%f", &aluno->materias[contador].nota);
        printf("Codigo:\n");
        scanf("%d", &aluno->materias[contador].codigo);
    }
    free(aluno->materias);
    free(aluno);
    return 0;
}