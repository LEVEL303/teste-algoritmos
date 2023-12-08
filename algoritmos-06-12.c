#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas = 5, colunas = 5, contadorLinhas, contadorColunas;
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    for(contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++) {
        matriz[contadorLinhas] = (int *) malloc(colunas * sizeof(int));
    } 

    for(contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++) {
        for(contadorColunas = 0; contadorColunas < colunas; contadorColunas++) {
            matriz[contadorLinhas][contadorColunas] = contadorLinhas * colunas + contadorColunas;
        }
    }

    for(contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++) {
        for(contadorColunas = 0; contadorColunas < colunas; contadorColunas++) {
            printf("%d ", matriz[contadorLinhas][contadorColunas]);
        }
        printf("\n");
    }
    
    for(contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++) {
        free(matriz[contadorLinhas]);
    }
    free(matriz);
    return 0;
}