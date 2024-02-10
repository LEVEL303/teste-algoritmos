#include "disciplina.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Disciplina ** disciplinas;
    Aluno ** alunos;
    int quant_disciplinas, quant_alunos;
    char nome_disciplina[100];
    char nome_aluno[100];
    int codigo_disciplina, matricula_aluno;
    int index_disciplina = -1, index_aluno = -1;
    int index, continuar;

    printf("Informe o numero de disciplinas a serem cadastradas:\n");
    scanf("%d", &quant_disciplinas);
    printf("Informe o numero de alunos a serem cadastrados:\n");
    scanf("%d", &quant_alunos);

    disciplinas = (Disciplina **) malloc(quant_disciplinas * sizeof(Disciplina *));
    alunos = (Aluno **) malloc(quant_alunos * sizeof(Aluno *));

    for(index = 0; index < quant_disciplinas; index++) {
        printf("===== Disciplina %d =====\n", index + 1);
        printf("Nome da disciplina:\n");
        scanf(" %[^\n]s", nome_disciplina);
        printf("Codigo da disciplina:\n");
        scanf("%d", &codigo_disciplina);
        disciplinas[index] = cria_disciplina(nome_disciplina, codigo_disciplina);
    }

    printf("-----------------------------------\n");

    for(index = 0; index < quant_alunos; index++) {
        printf("===== Aluno %d =====\n", index + 1);
        printf("Nome do aluno:\n");
        scanf(" %[^\n]s", nome_aluno);
        printf("Matricula do aluno:\n");
        scanf("%d", &matricula_aluno);
        alunos[index] = cria_aluno(nome_aluno, matricula_aluno);
    }

    printf("-----------------------------------\n");

    printf("Disciplinas cadastrada:\n");
    for(index = 0; index < quant_disciplinas; index++) {
        printf("%s\n", disciplinas[index]->nome);
    }

    printf("Alunos cadastrados:\n");
    for(index = 0; index < quant_alunos; index++) {
        printf("%s\n", alunos[index]->nome);
    }

    printf("-----------------------------------\n");
    
    printf("Gostaria de matricular um aluno em uma disciplina (1-sim 0-nao)?\n");
    scanf("%d", &continuar);
    while(continuar) {
        printf("Informe a matricula do aluno:\n");
        scanf("%d", &matricula_aluno);
        printf("Informe o codigo da disciplina:\n");
        scanf("%d", &codigo_disciplina);
        for(index = 0; index < quant_alunos; index++){
            if(alunos[index]->matricula == matricula_aluno) {
                index_aluno = index;
                break;
            }
        }
        if(index_aluno >= 0) {
            for(index = 0; index < quant_disciplinas; index++) {
                if(disciplinas[index]->codigo == codigo_disciplina) {
                    index_disciplina = index;
                    break;
                }
            }
            if(index_disciplina >= 0) {
                matricula_disciplina(alunos[index_aluno], disciplinas[index_disciplina]);
            } else {
                printf("Codigo de disciplina invalido!\n");
            }
        } else {
            printf("Matricula de aluno invalida!\n");
        }
        printf("Realizar mais matriculas (1-sim 0-nao)?\n");
        scanf("%d", &continuar);
    }

    printf("<<<< Dados dos alunos >>>>\n");
    for(index = 0; index < quant_alunos; index++) {
        printf("///// Aluno %d /////\n", index + 1);
        printf("Nome: %s \nMatricula %d \nQuantidade de disciplinas em que esta matriculado: %d\n",
        alunos[index]->nome, alunos[index]->matricula, alunos[index]->num_disciplinas);
        printf("Disciplinas do aluno %d:\n", index + 1);
        for(index_disciplina = 0; index_disciplina < alunos[index]->num_disciplinas; index_disciplina++) {
            printf("%s\n", alunos[index]->disciplinas[index_disciplina]->nome);
        }
    }

    for(index = 0; index < quant_alunos; index++) {
        exclui_aluno(alunos[index]);
    }
    free(alunos);
    for(index = 0; index < quant_disciplinas; index++) {
        exclui_disciplina(disciplinas[index]);
    }
    free(disciplinas);
    
    return 0;
}