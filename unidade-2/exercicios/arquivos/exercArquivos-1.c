#include <stdio.h>
#include <stdlib.h>

#define QUANT_ALUNOS 3
#define QUANT_NOTAS 3

typedef struct aluno {
    char nome[80];
    float * notas;
    float media;
} Aluno;

float calcularMedia(float * notas) {
    int i;
    float media = 0;
    for (i = 0; i < QUANT_NOTAS; i++) {
        media = media + notas[i];
    }
    return media / QUANT_NOTAS;
}

int main() {
    FILE * arq_entrada;
    Aluno * alunos = (Aluno *) malloc(QUANT_ALUNOS * sizeof(Aluno));
    int i, j;

    for (i = 0; i < QUANT_ALUNOS; i++) {
        alunos[i].notas = (float *) malloc(QUANT_NOTAS * sizeof(float));
    }

    arq_entrada = fopen("entrada.txt", "rt");
    if (arq_entrada == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    } else {
        printf("Arquivo aberto com sucesso.\n");
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        fscanf(arq_entrada, "%s", alunos[i].nome);
        printf("%s\n", alunos[i].nome);
        for (j = 0; j < QUANT_NOTAS; j++) {
            fscanf(arq_entrada, "%f", &alunos[i].notas[j]);
            printf("%.1f\n", alunos[i].notas[j]);
        }
    }

    if (fclose(arq_entrada) == 0) {
        printf("Arquivo fechado com sucesso.\n");
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        free(alunos[i].notas);
    }
    free(alunos);

    return 0;
}
