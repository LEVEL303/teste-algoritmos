/* Definição de novo tipo de dado: Fila */
typedef struct fila Fila;

/* Função que cria uma fila e retorna o seu endereço */
Fila * cria_fila(int tamanho_max);

/* Função que libera a memória de uma fila */
void destruir_fila(Fila ** fila);

/* Função que verifica se uma fila está vazia, retorna 1 para vazia e 0 para não vazia */
int fila_vazia(Fila * fila);

/* Função que verifica se uma fila está cheia, retorna 1 para cheia e 0 para não cheia */
int fila_cheia(Fila * fila);

/* Função que insere um novo elemento em uma fila */
int insere_fila(Fila * fila, int valor);

/* Função que remove o primeiro elemento de uma fila */
int remove_fila(Fila * fila);

/* Função que consulta o primeiro elemento de uma fila e o armazena em uma variável fornecida via parâmetro */
int consulta_fila(Fila * fila, int * elemento);
