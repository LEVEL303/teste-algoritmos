#include <stdio.h>

typedef enum bool{
    TRUE,
    FALSE
}Bool;

int main() {
    int resposta;
    printf("Voce gosta de algoritmos? (0-True 1-False)\n");
    scanf("%d", &resposta);
    if(resposta == TRUE) {
        printf("Boa escolha\n");
    } else if(resposta == FALSE) {
        printf("Que pena!\n");
    }
    return 0;
}