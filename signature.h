typedef struct nodo{
	char simbolos;
	struct nodo *prox;
} no;

no* cria_no (char);
void insere_pilha (no **, no *);
void desempilha (no **);
void libera_pilha (no **);
int verifica_expressao(char []);
