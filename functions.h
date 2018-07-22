no* cria_no (char letra){
	no*novo = (no*) malloc(sizeof(no));
	novo->simbolos = letra;
	novo->prox = NULL;
	return novo;
}

void insere_pilha (no**pilha, no*p){
	no *aux;
	
	if (!(*pilha)){
		*pilha = p;
	}
	else{
		aux = p;
		aux->prox = *pilha;
		*pilha = aux;
	}
}

void desempilha (no**pilha){
	no*aux = *pilha;
	*pilha = (*pilha)->prox;
	free (aux);
}

void libera_pilha (no**pi){
	no*tmp=NULL;
	while ((*pi)){
		tmp = *pi;
		*pi = (*pi)->prox;
		free(tmp);
	}
}

int verifica_expressao(char n[]){
	int cont=0;
	no*pilha_a, *pilha_f, *p;
	char abre[] = "{[(";
	char fecha[] = "}])";
	pilha_a = pilha_f = p= NULL;
	
	for (int i=0; i<strlen(n); i++){
		for (int j=0; j<3; j++){
			if (n[i] == abre[j]){
				p = cria_no(n[i]);
				insere_pilha (&pilha_a, p);
			}
			else if (n[i] == fecha[j]){
				p = cria_no(n[i]);
				insere_pilha  (&pilha_f, p);
			}
			if (pilha_a && pilha_f){
				if (pilha_a->simbolos == abre[j] && pilha_f->simbolos == fecha[j]){
					desempilha(&pilha_a);
					desempilha(&pilha_f);
				}
			}
		}
	}
	if (!pilha_a && !pilha_f)
		++cont;
		
	libera_pilha (&pilha_a);
	libera_pilha (&pilha_f);
	return cont;
}
