#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * arq;
    arq = fopen("Arq.txt","wt");
    if(arq == NULL) {
        printf("Erro ao criar o arquivo\n");
        exit(1);
    } else {
        printf("O arquivo foi criado\n");
    }

    if(fclose(arq) == 0) {
        printf("Arquivo fechado com sucesso\n");
    }
    return 0;
}