#include <stdio.h>
#include <stdlib.h>

#define QUANT_ALUNOS 4
#define QUANT_NOTAS 3
#define NOME_ARQUIVO "saida-exercicio-2.txt"

typedef struct aluno {
    char nome[80];
    float * notas;
}Aluno;

int main() {
    FILE * arq_saida = fopen(NOME_ARQUIVO, "w");
    Aluno * alunos = (Aluno *) malloc(QUANT_ALUNOS * sizeof(Aluno));
    int i, j;

    if(alunos == NULL) {
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    } 
    for(i = 0; i < QUANT_ALUNOS; i++) {
        alunos[i].notas = (float *) malloc(QUANT_NOTAS * sizeof(float));
        if(alunos[i].notas == NULL) {
            printf("Falha na alocacao de memoria!\n");
            exit(1);
        }
    }

    if(arq_saida == NULL) {
        printf("Falha ao tentar abrir '%s'!\n", NOME_ARQUIVO);
        exit(1);
    } else {
        printf("Arquivo '%s' aberto com sucesso.\n", NOME_ARQUIVO);
    }

    for(i = 0; i < QUANT_ALUNOS; i++) {
        printf("------ ALUNO %d ------\n", i+1);
        printf("Nome:\n");
        scanf(" %[^\n]s", alunos[i].nome);
        fprintf(arq_saida, "%s ", alunos[i].nome);
        for(j = 0; j < QUANT_NOTAS; j++) {
            printf("Nota %d:\n", j+1);
            scanf("%f", &alunos[i].notas[j]);
            fprintf(arq_saida, "%.1f ", alunos[i].notas[j]);
        }
        fprintf(arq_saida, "\n");
    }

    for(i = 0; i < QUANT_ALUNOS; i++) {
        free(alunos[i].notas);
    }
    free(alunos);

    if(fclose(arq_saida) == 0) {
        printf("Arquivo '%s' fechado com sucesso.\n", NOME_ARQUIVO);
    }

    return 0;
}