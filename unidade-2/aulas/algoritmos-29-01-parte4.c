#include <stdio.h>
#include <stdlib.h>

int main() {
    int c;
    int n_linhas = 0;
    FILE * arq;

    arq = fopen("arq_escrita.txt", "rt");
    if(arq == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }

    while((c = fgetc(arq)) != EOF) {
        if(c == '\n') {
            n_linhas++;
        }
    }
    fclose(arq);
    printf("Numero de linhas = %d\n", n_linhas);
    return 0;
}