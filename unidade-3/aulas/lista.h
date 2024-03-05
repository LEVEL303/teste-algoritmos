/* Definição da struct lista para Lista */
typedef struct lista Lista;

/* Função que inicializa a lista atribuindo NULL */
Lista * cria_lista();

/* Função que insere um novo elemento na lista */
Lista * insere_elemento(Lista * lista, int valor);

/* Função que imprime todos os elementos da lista */
void imprime_lista(Lista * lista);

/* Função que vereifica se a lista esta vazia (retorna 1 para vazia e 0 para não vazia) */
int lista_vazia(Lista * lista);

/* Função que busca um elemento na lista,
 se for encontrado, retornara o endereço do elemento, se não, retornara NULL */
Lista * busca_elemento(Lista * lista, int valor);

/* Função que deleta um elemento da lista */
void deleta_elemento(Lista* lista, Lista * no);