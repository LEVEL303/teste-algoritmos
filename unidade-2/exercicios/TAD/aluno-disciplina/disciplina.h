#ifndef DISCIPLINA_H
#define DISCIPLINA_H

/* Define um novo tipo de estrutura de dados: Disciplina */
typedef struct disciplina Disciplina;

/* Aloca dinamicamente uma estrutura do tipo Disciplina,
preenche ela com os dados fornecidos via parâmetros e retorna o endereço da estrutura. */
Disciplina * cria_disciplina(char nome[], int codigo);

/* Libera a memória alocada da estrutura do tipo Disciplina, fonecida via parâmetro. */
void exclui_disciplina(Disciplina * disciplina);
#endif