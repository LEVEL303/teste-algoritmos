/* TAD: Aluno */
#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

struct aluno {
    char nome[80];
    int matricula;
    float IRA;
};

Aluno * recebeDados() {
    Aluno * estudante = (Aluno *) malloc(sizeof(Aluno));
    if(estudante == NULL) {
        printf("Sem memoria!\n");
        exit(1);
    } 
    printf("Informe o nome do aluno:\n");
    scanf(" %[^\n]s", estudante->nome);
    printf("Informe a matricula do aluno:\n");
    scanf("%d", &estudante->matricula);
    printf("Informe o IRA do aluno:\n");
    scanf("%f", &estudante->IRA);
    
    return estudante;
}

Aluno ** recebeDadosAlunos(int quant_estudantes) {
    int index;
    Aluno ** estudantes = (Aluno **) malloc(quant_estudantes * sizeof(Aluno *));
    if(estudante == NULL) {
        printf("Sem memoria!\n");
        exit(1);
    }

    for(index = 0; index < quant_estudantes; index++) {
        printf("==== Aluno %d ====\n", index+)
        estudantes[index] = recebeDados();
    }
}

void exibirDados(Aluno * estudante) {
    printf("Nome: %s \nMatricula: %d \nIRA: %f\n", estudante->nome, estudante->matricula, estudante->IRA);
}

void liberarMemoria(Aluno * estudante) {
    free(estudante);
}