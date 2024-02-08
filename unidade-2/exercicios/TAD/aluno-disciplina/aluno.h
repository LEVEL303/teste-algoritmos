#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno * cria_aluno(char nome[], int matricula);
void matricula_disciplina(Aluno * aluno, Disciplina * disciplina);
void exclui_aluno(Aluno * aluno);

#endif