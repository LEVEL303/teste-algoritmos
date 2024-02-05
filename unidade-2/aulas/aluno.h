/* Definição de novo tipo: Aluno */
typedef struct aluno Aluno;

/* Função que aloca memoria para um struct aluno,
recebe os dados via teclado e retorna um ponteiro para Aluno * */
Aluno * recebeDados();

/* Função que exibe os dados de um tipo Aluno */
void exibirDados(Aluno * estudante);

/* Função que libera memória alocada */
void liberarMemoria(Aluno * estudante);