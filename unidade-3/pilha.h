/* Definição de um novo tipo dado: Pilha */
typedef struct pilha Pilha;

/* Função que cria uma pilha e retorna o seu endereço */
Pilha * pilha_cria(void);

/* Função que adiciona um novo elemento em uma pilha */
void pilha_push(Pilha * pilha, float valor);

/* Função que verifica se uma pilha está vazia,
 se estiver vazia retorna 1 se não retorna 0 */
int pilha_vazia(Pilha * pilha);

/* Função que retira o elemento do topo da pilha e o retorna */
float pilha_pop(Pilha * pilha);

/* Função que libera a memória de uma pilha */
void pilha_libera(Pilha * pilha);

/* Função que imprime os valores de uma pilha */
void pilha_imprime(Pilha * pilha);
