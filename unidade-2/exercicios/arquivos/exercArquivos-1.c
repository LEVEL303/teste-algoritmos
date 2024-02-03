#include <stdio.h>
#include <stdlib.h>

#define QUANT_ALUNOS 3
#define QUANT_NOTAS 3
#define NOME_ARQUIVO_ENTRADA "entrada-1.txt"
#define NOME_ARQUIVO_SAIDA "saida-1.txt"

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
    FILE * arq_entrada = fopen(NOME_ARQUIVO_ENTRADA, "rt");
    FILE * arq_saida = fopen(NOME_ARQUIVO_SAIDA, "wt");
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
        printf("Erro ao abrir arquivo '%s'!\n", NOME_ARQUIVO_ENTRADA);
        exit(1);
    } else {
        printf("Arquivo '%s' aberto com sucesso.\n", NOME_ARQUIVO_ENTRADA);
    }

    if (arq_saida == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", NOME_ARQUIVO_SAIDA);
        exit(1);
    } else {
        printf("Arquivo '%s' aberto com sucesso.\n", NOME_ARQUIVO_SAIDA);
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
        printf("Arquivo '%s' fechado com sucesso.\n", NOME_ARQUIVO_ENTRADA);
    }
    if (fclose(arq_saida) == 0) {
        printf("Arquivo '%s' fechado com sucesso.\n", NOME_ARQUIVO_SAIDA);
    }

    for (i = 0; i < QUANT_ALUNOS; i++) {
        free(alunos[i].notas);
    }
    free(alunos);

    return 0;
}
