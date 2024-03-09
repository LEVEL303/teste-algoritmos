/* Definição de novo tipo de dado: ListaDE */
typedef struct listade ListaDE;

/* Função que inicializa uma lista retornando NULL */
ListaDE * criaListaDE(void);

/* Função que verifica se uma lista está vazia, retorna 1 para vazia e 0 para não vazia */
int listaVazia(ListaDE * lista);

/* Função que insere um novo nó em uma lista duplamente encadeada */
ListaDE * insereNoLDE(ListaDE * lista, int valor);

/* Função que apaga todos os nós de uma lista duplamente encadeada */
void liberaListaDE(ListaDE * lista);

/* Função que busca um nó, de um valor especificado, em uma lista duplamente encadeada e,
 se for encontrado, retorna o endereço do nó, se não for encontrado retorna NULL*/
ListaDE * buscaNoLDE(ListaDE * lista, int valor);

/* Função que retira todas as ocorrências de um determinado valor de uma lista duplamente encadeada
 e retorna o endereço, atualizado, do primeiro nó da lista */
ListaDE * retiraValorLDE(ListaDE * lista, int valor);

/* Função que imprime o valor de cada nó de uma lista duplamente encadeada */
void imprimeListaDE(ListaDE * lista);