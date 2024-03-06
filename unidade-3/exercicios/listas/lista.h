/* Definição da struct lista para Lista */
typedef struct lista Lista;

/* Função que inicializa a lista atribuindo NULL */
Lista * cria_lista();

/* Função que insere um novo elemento na lista e retorna o seu endereço */
Lista * insere_elemento(Lista * lista, int valor);

/* Função que imprime todos os elementos da lista */
void imprime_lista(Lista * lista);

/* Função que vereifica se a lista esta vazia (retorna 1 para vazia e 0 para não vazia) */
int lista_vazia(Lista * lista);

/* Função que busca um elemento na lista,
 se for encontrado, retornara o endereço do elemento, se não, retornara NULL */
Lista * busca_elemento(Lista * lista, int valor);

/* Função que deleta um elemento da lista e retonar o endereço do seu primeiro elemento,
caso o elemento deletado seja o primeiro da lista será retonado o endereço do segundo elemento */
Lista * deleta_elemento(Lista* lista, Lista * no);

/* Função que retorna a quantidade de elementos que são maiores que o elemento informado */
int maiores(Lista * lista, int valor);

/* Função que retorna o endereço do último elemento da lista */
Lista * ultimo(Lista * lista);

/* Função que concatena duas listas */
Lista * concatena(Lista * lista_1, Lista * lista_2);

/* Função que remove todas as ocorrências de um valor específico da lista
 e retorna o endereço da lista atualizada */
Lista * retira_valor(Lista * lista, int valor);