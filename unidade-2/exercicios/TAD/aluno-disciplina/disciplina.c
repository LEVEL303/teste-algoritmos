#include "disciplina.h"
#include <stdlib>
#include <string.h>

struct disciplina {
    char nome[100];
    int codigo;
};

Disciplina * cria_disciplina(char nome[], int codigo) {
    Disciplina * disciplina = (Disciplina *) malloc(sizeof(Disciplina));
    if(disciplina == NULL) {
        exit(1);
    }
    strcpy(disciplina->nome, nome);
    disciplina->codigo = codigo;
    
    return desciplina; 
}

void exclui_disciplina(Disciplina * disciplina) {
    free(disciplina);
}