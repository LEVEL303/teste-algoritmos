#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * arq;
    int c;
    char s[20];

    arq = fopen("Arq.txt","r");
    if(arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    } else {
        printf("Arquivo aberto como sucesso\n");
    }
    
    //c = fgetc(arq);
    //printf("%c\n", c);

    //fgets(s, 20, arq);
    //printf("%s\n", s);

    fscanf(arq, "%s", s);
    printf("%s\n", s);

    if(fclose(arq) == 0) {
        printf("Arquivo fechado com sucesso\n");
    }
    return 0;
}