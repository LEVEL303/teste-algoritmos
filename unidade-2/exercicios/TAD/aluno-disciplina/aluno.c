#include "aluno.h"
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[100];
    int matricula;
    Disciplina * disciplinas[10];
    int num_disciplinas;
};

Aluno * cira_aluno(char nome[], int matricula) {
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno));
    if(aluno == NULL) {
        exit(1);
    } 
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->num_disciplinas = 0;
    
    return aluno;
}

void matricula_disciplina(Aluno * aluno, Disciplina * disciplina) {
    if(aluno->num_disciplinas < 10) {
        int index;
        for(index = 0; index < num_disciplinas; index++) {
            if(aluno->disciplinas[index].codigo == disciplina->codigo) {
                return;
            }
        }
        aluno->disciplinas[num_dicsiplinas] = disciplina;
        aluno->num_disciplinas++;
    }
}

void exclui_aluno(Aluno * aluno) {
    free(aluno);
}