typedef struct lista Lista;

/* Função inicializa a lista atribuindo NULL */
Lista * cria_lista();

/* Função que insere elemento inteiro na lista */
Lista * insere_elemento(Lista * lista, int valor);

/* Função que imprime todos os elementos de uma lista */
void imprime_lista(Lista * lista);

/* Função que vereifica se a lista esta vazia, retorna 1 para vazia e 0 para não vazia */
int check_lista(Lista * lista);

/* Função que busca um elemento do tipo inteiro em uma lista,
 se for encontrado, retornara o endereço do elemento, se não, retornara NULL */
void busca(Lista * lista, int valor);