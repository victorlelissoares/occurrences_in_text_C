#include "listadecc.h"

/*cria nova lista duplamente encadeada vazia, e retorna um ponteiro para a mesma*/
ldecc *cria_nova_ldecc(){
	ldecc *lista;

	lista = (ldecc*) malloc(sizeof(ldecc));
	lista->cabeca = (no*) malloc(sizeof(no));
	lista->cabeca->prox = lista->cabeca->ant = NULL;

	return lista;
}

/*imprime uma lista duplamente encadeada*/
void imprime_ldecc(ldecc *lista, int num_arquivos){
	no *p;
	int i=0;

	if(lista->cabeca->prox == NULL)
		printf("Lista vazia\n");

	for(p=lista->cabeca->prox; p != NULL; p = p->prox){
		printf("%s", p->chave);
		for(i=0; i<num_arquivos; i++){
			printf(" %d", p->ocorrencias[i]);
		}
		printf("\n");
	}
}

/*converte uma palavra de sua versão maiúscula para minúscula*/
void cnvr_lw(char frase[MAX]){
	int i=0;

	while(frase[i] != '\0'){

		if(memcmp(frase+i, "Á", 2)==0){
			memcpy(frase+i, "á", sizeof("á"));
		}
		else if(memcmp(frase+i, "É", 2)==0){
			memcpy(frase+i, "é", 2);
		}
		else if(memcmp(frase+i, "Í", 2)==0){
			memcpy(frase+i, "í", 2);
		}
		else if(memcmp(frase+i, "Ó", 2)==0){
			memcpy(frase+i, "ó", 2);
		}
		else if(memcmp(frase+i, "Ú", 2)==0){
			memcpy(frase+i, "ú", 2);
		}

		else if(memcmp(frase+i, "À", 2)==0){
			memcpy(frase+i, "à", 2);
		}

		else if(memcmp(frase+i, "Â", 2)==0){
			memcpy(frase+i, "â", 2);
		}
		else if(memcmp(frase+i, "Ê", 2)==0){
			memcpy(frase+i, "ê", 2);
		}
		else if(memcmp(frase+i, "Ô", 2)==0){
			memcpy(frase+i, "ô", 2);
		}


		else if(memcmp(frase+i, "Ã", 2)==0){
			memcpy(frase+i, "ã", 2);
		}
		else if(memcmp(frase+i, "Õ", 2)==0){
			memcpy(frase+i, "õ", 2);
		}

		else if(memcmp(frase+i, "Ç", 2)==0){
			memcpy(frase+i, "ç", 2);
		}

		frase[i] = tolower(frase[i]);
		i++;
	}
}

void insere_ordenado_ldecc(ldecc *lista, char palavra[MAX], int num_arquivos, int arq_atual){
	no *novo;
	no *p, *q;

	/*aloca novo nó*/
	novo = (no*) malloc(sizeof(no));
	/*copia palavra para a chave do novo nó*/
	strcpy(novo->chave, palavra);
	/*aloca o vetor de ocorrencias de cada nó*/
	novo->ocorrencias = (int*) malloc(num_arquivos * sizeof(int));
	/*agora tenho que buscar um nó, ou inserir como é predefinido
	ou, incrementar caso já exista o nó*/

	/*p estará na cabeça e q, estará no primeiro nó*/
	/*enquanto a string do novo nó for maior que as demais, andarei na lista
	a condição de parada é quando achar, um elemento maior ou igual*/
	for(p=lista->cabeca, q=p->prox; q!=NULL && strcmp(novo->chave, q->chave) > 0; p=q, q=q->prox)
		;

	/*caso o nó em que o q parou tenha a chave igual a que quer que seja inserida*/
	/*incrementa o num de ocorrencias na posição do vetor correspondente*/
	if(q!= NULL && strcmp(novo->chave, q->chave)  == 0){
		q->ocorrencias[arq_atual]++;
	}else{
		novo->prox = q;
		novo->ant = p;
		p->prox = novo;
		novo->ocorrencias[arq_atual]++;
		/*se a lista não estiver vazia, posso acessar o campo ant */
		if(q!=NULL){
			q->ant=novo;
		}
	}
}
