#ifndef ALUNO_H
#define ALUNO_H
#include "disciplina.h"

/* Define um novo tipo de estrutura de dados: Aluno */
typedef struct aluno Aluno;

/* Aloca dinamicamente uma estrutura do tipo Aluno, 
preenche ela com os dados fornecidos via parâmetros e retorna o endereço da estrutura. */
Aluno * cria_aluno(char nome[], int matricula);

/* Realiza o processo de matrícula do aluno, fonecido via parâmetro, na disciplina, fornecida 
via parâmetro, caso o aluno não tenha chgado ao limite de disciplinas e ele ainda não
esteja matriculado na disciplina especificada. */
void matricula_disciplina(Aluno * aluno, Disciplina * disciplina);

/* Libera a memória alocada da estrutura do tipo Aluno, fornecida via parâmetro. */
void exclui_aluno(Aluno * aluno);

#endif