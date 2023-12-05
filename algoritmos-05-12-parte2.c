#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *nome = (char*) malloc(50 * sizeof(char));
    if(nome == NULL) {
        exit(1);
    }
    printf("Digite o seu nome:\n");
    scanf("%[^\n]", nome);
    
    nome = (char*) realloc(nome, strlen(nome) * sizeof(char));
    
    printf("%s", nome);
    free(nome);
    return 0;
}