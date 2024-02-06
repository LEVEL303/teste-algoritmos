#include "aluno.h"

int main() {
    Aluno * aluno;
    Aluno * alunos;
    aluno = recebeDados();
    alunos = recebeDadosVariosAlunos(3);
    exibirDados(aluno, 1);
    exibirDados(alunos, 3);

    liberarMemoria(aluno);
    liberarMemoria(alunos);
    return 0;
}