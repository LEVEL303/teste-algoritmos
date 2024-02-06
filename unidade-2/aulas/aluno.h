/* Definição de novo tipo: Aluno */
typedef struct aluno Aluno;

/* Função que aloca memória para um struct aluno,
recebe os dados via teclado e retorna um ponteiro para Aluno * */
Aluno * recebeDados();

/* Função que aloca memória para varias structs aluno,
recebe os dados de cada struct via teclado e retorna um ponteiro para Aluno */
Aluno * recebeDadosVariosAlunos(int quant_estudantes);

/* Função que exibe os dados de um tipo Aluno */
void exibirDados(Aluno * estudante, int quant_estudantes);

/* Função que libera memória alocada */
void liberarMemoria(Aluno * estudante);