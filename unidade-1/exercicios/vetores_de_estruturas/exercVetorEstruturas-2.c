#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 5

typedef struct aluno {
    int matricula;
    char nome[80];
    char turma;
    float notas[3];
    float media;
}Aluno;

void matricula(Aluno * aluno) {
    int i;
    for(i = 0; i < MAX_ALUNOS; i++) {
        printf("\t=== Aluno %d ===\n", i+1);
        printf("Numero de matricula: ");
        scanf("%d", &aluno[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]s", aluno[i].nome);
        do {
            printf("Turma (A ou B): ");
            scanf(" %c", &aluno[i].turma);
            if(aluno[i].turma != 'A' && aluno[i].turma != 'B') {
                printf("Turma invalida! Tente novamente.\n");
            }
        } while(aluno[i].turma != 'A' && aluno[i].turma != 'B');
    }
}

void lancaNotas(Aluno * aluno) {
    int i, j;
    float media = 0;
    for(i = 0; i < MAX_ALUNOS; i++) {
        printf("Informe as notas do aluno %d:\n", i+1);
        for(j = 0; j < 3; j++) {
            printf("Nota %d: ", j+1);
            scanf("%f", &aluno[i].notas[j]);
            media = media + aluno[i].notas[j];
        }
        aluno[i].media = media / 3;
        media = 0;
    }
}

void imprimirTudo(Aluno * aluno) {
    int i, j;
    for(i = 0; i < MAX_ALUNOS; i++) {
        printf("\t+++ Aluno %d +++\n", i+1);
        printf("Matricula: %d \nNome: %s \nTurma: %c \n", 
        aluno[i].matricula, aluno[i].nome, aluno[i].turma);
        for(j = 0; j < 3; j++) {
            printf("Nota %d: %.2f\n", j+1, aluno[i].notas[j]);
        }
        printf("Media: %.2f\n", aluno[i].media);
    }
}

void imprimirTurma(Aluno * aluno, char turma) {
    int i, j;
    for(i = 0; i < MAX_ALUNOS; i++) {
        if(aluno[i].turma == turma) {
            printf("\t+++ Aluno %d +++\n", i+1);
            printf("Matricula: %d \nNome: %s \nTurma: %c \n", 
            aluno[i].matricula, aluno[i].nome, aluno[i].turma);
            for(j = 0; j < 3; j++) {
                printf("Nota %d: %.2f\n", j+1, aluno[i].notas[j]);
            }
            printf("Media: %.2f\n", aluno[i].media);
        }
    }
}

void imprimirTurmaAprovados(Aluno * aluno, char turma) {
    int i;
    for(i = 0; i < MAX_ALUNOS; i++) {
        if(aluno[i].turma == turma && aluno[i].media >= 7.0) {
            printf("Nome: %s\n", aluno[i].nome);
            printf("Media: %.2f\n", aluno[i].media);
            printf("=================\n");
        }
    }
}

int main() {
    Aluno * alunos_matriculados = (Aluno *) malloc(MAX_ALUNOS * sizeof(Aluno));
    char turma;
    if(alunos_matriculados == NULL) {
        printf("Erro de alocacao de memoria!");
        exit(1);
    }

    matricula(alunos_matriculados);
    lancaNotas(alunos_matriculados);

    printf("=== Dados de todos os alunos ===\n");
    imprimirTudo(alunos_matriculados);

    do {
        printf("Informe uma turma (A ou B) para ver os alunos matriculados nela:\n");
        scanf(" %c", &turma);
        if(turma != 'A' && turma != 'B') {
            printf("Turma Invalida! Tente novamente.\n");
        }
    } while(turma != 'A' && turma != 'B');
    printf("=== Dados dos alunos da turma %c ===\n", turma);
    imprimirTurma(alunos_matriculados, turma);

    do {
        printf("Informe uma turma (A ou B) para ver os alunos Aprovados nela:\n");
        scanf(" %c", &turma);
        if(turma != 'A' && turma != 'B') {
            printf("Turma Invalida! Tente novamente.");
        }
    } while(turma != 'A' && turma != 'B');
    printf("=== Alunos aprovados da turma %c ===\n", turma);
    imprimirTurmaAprovados(alunos_matriculados, turma);

    free(alunos_matriculados);
    return 0;
}