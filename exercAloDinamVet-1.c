#include <stdio.h>
#include <stdlib.h>

int main() {
    int Npessoas = 10;
    int contador;
    int quantHomens = 0, quantMulheres = 0;
    int quantHNaoGostaram = 0, quantMGostaram = 0;
    float porcentagemH, porcentagemM;
    char *sexo = (char *) malloc(Npessoas * sizeof(char));
    char *opiniao = (char *) malloc(Npessoas * sizeof(char));
    
    for(contador = 0; contador < Npessoas; contador++) {
        printf("Digite o seu sexo (m/f):\n");
        scanf(" %c", &sexo[contador]);

        printf("Digite a sua opiniao sobre o novo produto (gostou/nao gostou):\n");
        scanf(" %c", &opiniao[contador]);
    }

    for(contador = 0; contador < Npessoas; contador++) {
        if(sexo[contador] == 'm') {
            quantHomens++;
        } else if(sexo[contador] == 'f') {
            quantMulheres++;
        }

        if(sexo[contador] == 'm' && opiniao[contador] == 'n') {
            quantHNaoGostaram++;
        }
        if(sexo[contador] == 'f' && opiniao[contador] == 'g') {
            quantMGostaram++;
        }
    }

    if(quantHomens != 0) {
        porcentagemH = (float)quantHNaoGostaram / quantHomens * 100;
        printf("%.1f%% dos homems, que responderam o questionario, nao gostaram do novo produto\n", porcentagemH);
    } else {
        printf("Nenhum Homem respondeu o questionario\n");
    }
    if(quantMulheres != 0) {
        porcentagemM = (float)quantMGostaram / quantMulheres * 100;
        printf("%.1f%% das mulheres, que respoderam o questionario, gostaram do novo produto\n", porcentagemM);
    } else {
        printf("Nenhuma mulher respondeu o questionario\n");
    }
    
    free(sexo);
    free(opiniao);
    return 0;
}