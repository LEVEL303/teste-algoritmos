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
    FILE * arq_entrada = fopen("entrada.txt", "rt");
    FILE * arq_saida = fopen("saida.txt", "wt");
    Aluno * alunos = (Aluno *) malloc(QUANT_ALUNOS * sizeof(Aluno));
    int i, j;

    if(alunos == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        alunos[i].notas = (float *) malloc(QUANT_NOTAS * sizeof(float));
        if(alunos[i].notas == NULL) {
            printf("Erro na alocacao de memoria!\n");
            exit(1);
        }
    }
    
    if (arq_entrada == NULL) {
        printf("Erro ao abrir arquivo 'entrada.txt'!\n");
        exit(1);
    } else {
        printf("Arquivo 'entrada.txt' aberto com sucesso.\n");
    }

    if (arq_saida == NULL) {
        printf("Erro ao abrir arquivo 'saida.txt'!\n");
        exit(1);
    } else {
        printf("Arquivo 'saida.txt' aberto com sucesso.\n");
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        fscanf(arq_entrada, "%s", alunos[i].nome);
        for (j = 0; j < QUANT_NOTAS; j++) {
            fscanf(arq_entrada, "%f", &alunos[i].notas[j]);
        }
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        alunos[i].media = calcularMedia(alunos[i].notas);
        
        fprintf(arq_saida, "%s %.1f %s\n", alunos[i].nome, alunos[i].media, 
        alunos[i].media >= 7.0 ? "Aprovado" : "Reprovado");
    }

    if (fclose(arq_entrada) == 0) {
        printf("Arquivo 'entrada.txt' fechado com sucesso.\n");
    }
    if (fclose(arq_saida) == 0) {
        printf("Arquivo 'saida.txt' fechado com sucesso.\n");
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        free(alunos[i].notas);
    }
    free(alunos);

    return 0;
}
