#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * arq = fopen("arq_escrita.txt", "wt");

    if(arq == NULL) {
        printf("Erro ao criar o arquivo\n");
        exit(1);
    } else {
        printf("Arquivo aberto como sucesso\n");
    }
    
    //fputc('A', arq);
    //fputs("Hello world!", arq);
    //fprintf(arq, "Texto");

    if(fclose(arq) == 0) {
        printf("Arquivo fechado com sucesso\n");
    }
    return 0;
}