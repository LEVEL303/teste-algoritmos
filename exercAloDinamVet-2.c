#include <stdio.h>
#include <stdlib.h>

int main() {
    int NQuestoes;
    int contador, contadorVet;
    char resposta;
    float nota = 0.0;
    int NAprovados = 0;
    float porcentagemAprovados;
    
    printf("Digite o numero de questoes da prova:\n");
    scanf("%d", &NQuestoes);
    while(getchar() != '\n');
    char *gabarito = (char *) malloc(NQuestoes * sizeof(char));

    printf("Digite o gabarito da prova:\n");
    for(contadorVet = 0; contadorVet < NQuestoes; contadorVet++) {
        printf("Questao %d:\n", contadorVet+1);
        scanf("%c", &gabarito[contadorVet]);
        while(getchar() != '\n');
    }

    for(contador = 1; contador <= 10; contador++) {
        printf("Digite as respostas da %d prova:\n", contador);
        for(contadorVet = 0; contadorVet < NQuestoes; contadorVet++) {
            printf("Questao %d:\n", contadorVet+1);
            scanf("%c", &resposta);
            while(getchar() != '\n');
            if(resposta == gabarito[contadorVet]) {
                nota += 10/NQuestoes;
            }
        }
        printf("Nota do aluno: %.1f\n", nota);
        if(nota >= 6) {
            NAprovados++;
        }
        nota = 0.0;
    }
    porcentagemAprovados = (float)NAprovados / 10 * 100;
    printf("A porcentagem de aprovacao foi de %.1f%%\n", porcentagemAprovados);
    free(gabarito);
    return 0;
}