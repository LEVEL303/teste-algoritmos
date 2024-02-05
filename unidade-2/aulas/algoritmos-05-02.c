#include "aluno.h"

int main() {
    Aluno * aluno;
    aluno = recebeDados();
    exibirDados(aluno);
    liberarMemoria(aluno);
    return 0;
}